#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
namespace bs_index
{
    // 描述文档信息
    struct doc_info_t
    {
        std::string title;   // 文档标题
        std::string content; // 文档内容
        std::string url;     // 文档url
        uint64_t doc_id;     // 文档id
    };
    // 倒排元素
    struct inverted_elem_t
    {
        uint64_t doc_id;      // 文档id
        std::string key_word; // 关键字
        int weight;           // 权重
    };
    // 倒排拉链
    typedef std::vector<inverted_elem_t> inverted_list_t;
    class index
    {
    private:
        // 正排索引用动态顺序表 下标天然为文档id
        std::vector<doc_info_t> _forward_index;
        // 倒排索引一定是 一个关键字对应一个/组倒排元素对应[关键字和倒排拉链的映射关系]
        std::unordered_map<std::string, inverted_list_t> _inverted_index;

    public:
        index();
        ~index();

    public:
        // 根据文档id 通过正排索引获取文档信息
        doc_info_t *get_doc_info(const uint64_t doc_id)
        {
            if (doc_id >= _forward_index.size())
            {
                std::cerr << "doc_id is out of range!" << std::endl;
                return nullptr;
            }
            return &_forward_index[doc_id];
        }
        // 根据关键字 通过倒排索引获取倒排拉链(包含文档id)
        inverted_list_t *get_inverted_list(const std::string key_word)
        {
            auto iter = _inverted_index.find(key_word);
            if (iter == _inverted_index.end())
            {
                std::cerr << "not found in inverted_index" << std::endl;
                return nullptr;
            }
            return &(iter->second);
        }
        // 根据完成数据清洗后的html文件 构建正派和倒排索引
        bool build_index(const std::string &file_path)
        {
            // 创建输入文件流
            std::ifstream ifs(file_path, std::ios_base::in | std::ios_base::binary);
            if (!ifs.is_open())
            {
                std::cerr << "failed to open input file! "
                          << "file name:" << file_path << std::endl;
                return false;
            }
            // 按行读取文档信息
            std::string line;
            while (std::getline(ifs, line))
            {
                // 动态建立正排索引
                doc_info_t *p_doc = build_forward_index(line);
                if (p_doc == nullptr)
                {
                    std::cerr << "line[" << line << "]is corrupted" << std::endl;
                    continue;
                }
                // 动态完善倒排索引
                build_inverted_index(*p_doc);
            }
            return true;
        }

    private:
        doc_info_t *build_forward_index(const std::string &line);
        bool build_inverted_index(const doc_info_t &doc_info);
    };
}

#include <iostream>
#include <vector>
#include <string>
// 引入boost准标准库完成复杂的文件操作
#include <boost/filesystem.hpp>
// 自定义工具集合
#include "util.hpp"
// 用于描述文档信息的结构
struct doc_info_t
{
    std::string title;
    std::string content;
    std::string url;
};
// const & 输入    (可传只读的参数)
//& 输出/输入输出 (必须是可写入的参数)
bool get_file_list(const std::string &src_path, std::vector<std::string> &output_list)
{
    namespace file_sys = boost::filesystem;
    std::vector<std::string> file_list;
    // 定义path对象
    file_sys::path root_path(src_path);
    //  确定path路径合法
    if (!file_sys::exists(root_path))
    {
        std::cerr << "src_path do not exists!" << std::endl;
        return false;
    }
    // 递归遍历
    //  定义一个空的递归迭代器判断递归结束
    file_sys::recursive_directory_iterator end;
    for (file_sys::recursive_directory_iterator it(root_path); it != end; it++)
    {
        // 不是普通文件的情况-普通文件包含网络文件
        if (!file_sys::is_regular_file(it->path()))
        {
            continue;
        }
        // 进一步筛选出网络文件
        if (it->path().extension() != ".html")
        {
            continue;
        }
        // 输出网页文件路径
        // std::cout <<"debug::"<< it->path().string() << std::endl;
        output_list.push_back(it->path().string());
    }
    return true;
};
bool parse_title(const std::string &file_str, std::string &output)
{
    return true;
}
bool parse_content(const std::string &file_str, std::string &output)
{
    return true;
}
bool parse_url()
{
    return true;
}
bool parse_html(const std::vector<std::string> &file_list, std::vector<doc_info_t> &output_list)
{
    // 遍历file_list
    for (const std::string &file_path : file_list)
    {
        // 读取文件 -若失败接着处理其他文件
        std::string file_str;
        if (!bs_util::file_util::read_file(file_path, file_str))
        {
            std::cerr << "failed to read file ::" << file_path << std::endl;
            continue;
        }
        // 定义描述对象
        doc_info_t doc_info;
        // 解析出标题
        if (!parse_title(file_str, doc_info.title))
        {
            std::cerr << "failed to parse title" << std::endl;
            continue;
        }
        // 清洗出文件内容(去标签)
        if (!parse_content(file_str, doc_info.content))
        {
            std::cerr << "failed to parse content" << std::endl;
            continue;
        }
        // 解析出路径 构建url
        if (!parse_url())
        {
            std::cerr << "failed to parse url" << std::endl;
            continue;
        }
        // 输出 结果
        output_list.push_back(doc_info);
    }

    return true;
}
bool save_html(const std::vector<doc_info_t> &parse_result, const std::string &output_file)
{
    return true;
}

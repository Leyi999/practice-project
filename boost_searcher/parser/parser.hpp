#pragma once
#include <iostream>
#include <vector>
#include <string>
// 引入boost准标准库完成复杂的文件操作
#include <boost/filesystem.hpp>
// 自定义工具集合
#include "../util.hpp"
// 文件路径
const std::string src_path = "../data/input/";
const std::string output_file = "../data/raw_html/raw.html";
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
        output_list.push_back(std::move(it->path().string()));
    }
    return true;
};
bool parse_title(const std::string &file_str, std::string &output)
{
    // 起始标签
    size_t begin = file_str.find("<title>");
    if (begin == std::string::npos)
        return false;
    // 结束标签
    size_t end = file_str.find("</title>");
    if (end == std::string::npos)
        return false;
    // 提取出 title
    begin += std::string("<title>").size();
    output = file_str.substr(begin, end - begin);
    return true;
}
bool parse_content(const std::string &file_str, std::string &output)
{
    // 枚举状态
    enum class parse_status_t
    {
        TITLE,
        CONTENT
    };
    parse_status_t cur_status(parse_status_t::TITLE);
    // 遍历html
    for (char c : file_str)
    {
        // 动态标签清洗
        switch (cur_status)
        {
        case parse_status_t::TITLE:
            if (c == '>')
                cur_status = parse_status_t::CONTENT;
            break;
        case parse_status_t::CONTENT:
            if (c == '<')
                cur_status = parse_status_t::TITLE;
            else
            {
                // 不保留'\n' 方便用换行符作为分隔符
                if (c == '\n')
                    c = ' ';
                output.push_back(c);
            }
        }
    }
    return true;
}
bool parse_url(const std::string &file_path, std::string &output)
{
    // 拼接出文档原始url
    static const std::string url_head("https://www.boost.org/doc/libs/1_81_0/doc/html/");
    std::string url_tail(file_path.substr(src_path.size()));
    output = url_head + url_tail;
    return true;
}
// for debug
static void show_doc(doc_info_t &doc_info)
{
    std::cout << "debug:: title:" << doc_info.title << std::endl;
    std::cout << "debug:: content:" << doc_info.content << std::endl;
    std::cout << "debug::url:" << doc_info.url << std::endl;
}
bool parse_html(const std::vector<std::string> &file_list, std::vector<doc_info_t> &output_list)
{
    // 遍历file_list
    for (const std::string &file_path : file_list)
    {
        // 读取文件 -若失败接着处理其他文件
        std::string file_str;
        if (!bs_util::file_util::read_file(file_path, file_str,std::ios_base::in))
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
        if (!parse_url(file_path, doc_info.url))
        {
            std::cerr << "failed to parse url" << std::endl;
            continue;
        }
        // debug
        //  static int n=0;
        //  show_doc(doc_info);
        //  if(n++==3)break;
        // 输出 结果
        output_list.push_back(std::move(doc_info));
    }

    return true;
}
bool save_html(const std::vector<doc_info_t> &parse_result, const std::string &output_file)
{
#define delimiter ('\3')
    // 输出文件流对象
    std::ofstream ofs(output_file, std::ios_base::out | std::ios_base::binary);
    if (!ofs.is_open())
    {
        std::cerr << "failed to create output file stream! "
                  << "file name:" << output_file << std::endl;
        return false;
    }
    for (const doc_info_t &doc_info : parse_result)
    {
        // 序列化
        std::string output_str;
        output_str = doc_info.title + delimiter + doc_info.content + delimiter + doc_info.url + '\n';
        // 写入文件
        ofs.write(output_str.c_str(), output_str.size());
    }
    ofs.close();
    return true;
}

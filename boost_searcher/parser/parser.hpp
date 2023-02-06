#include <iostream>
#include <vector>
#include <string>
struct doc_info_t
{
    std::string title;
    std::string content;
    std::string url;
};
//const & 输入    (可传只读的参数)
//& 输出/输入输出 (必须是可写入的参数)
bool get_file_list(const std::string &path, std::vector<std::string> &output_list)
{
    std::vector<std::string> file_list;
    return true;
};
bool parse_html(const std::vector<std::string> &file_list, std::vector<doc_info_t> &output_list)
{
    return true;
}
bool save_html(const std::vector<doc_info_t> &parse_result, const std::string &output_file)
{
    return true;
}

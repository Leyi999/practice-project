#include "parser.hpp"
const std::string src_path = "../data/input/";
const std::string output_file = "../data/raw_html/raw.html";
int main()
{
    // 1.拿到每个文件名+路径整理成file_list 方便以后读取
    std::vector<std::string> file_list;
    if (!get_file_list(src_path, file_list))
    {
        std::cerr << "get_file_list_error!" << std::endl;
        return 1;
    }
    // 2.按照file_list读取并解析文件
    std::vector<doc_info_t> parser_result;
    if (!parse_html(file_list, parser_result))
    {
        std::cerr << "parse_html_error!" << std::endl;
        return 2;
    }
    // 3.把解析完成后的文件内容,写入output_file,每个文件内容按/3分隔
    if (!save_html(parser_result, output_file))
    {
        std::cerr << "save_html_error!" << std::endl;
    }
    return 0;
}

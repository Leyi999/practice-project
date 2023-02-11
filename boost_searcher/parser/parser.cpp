#include "parser.hpp"
int main()
{
    // 1.拿到每个文件名+路径整理成file_list 方便以后读取
    std::vector<std::string> file_list;
    if (!get_file_list(src_path, file_list))
    {
        std::cerr << "failed to get file list!" << std::endl;
        return 1;
    }
    // 2.按照file_list读取并解析文件
    std::vector<doc_info_t> parser_result;
    if (!parse_html(file_list, parser_result))
    {
        std::cerr << "failed to parse html!" << std::endl;
        return 2;
    }
    // 3.把解析完成后的文件内容,写入output_file,每个文件内容按/3分隔
    if (!save_html(parser_result, output_file))
    {
        std::cerr << "failed to save html!" << std::endl;
    }
    return 0;
}

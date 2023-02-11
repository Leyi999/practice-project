#include <iostream>
#include <fstream>
#include <string>
namespace bs_util
{
    class file_util
    {
    public:
        static bool read_file(const std::string &file_path, std::string &output)
        {
            // 输入文件流对象
            std::ifstream ifs(file_path.c_str(), std::ios_base::in);
            if (!ifs.is_open())
            {
                std::cerr << "failed to create input file stream! "
                          << "file name:" << file_path << std::endl;
                return false;
            }
            // 按行读取 并输出
            for (std::string tmp; std::getline(ifs, tmp); output += tmp)
                ;
            ifs.close();
            return true;
        }
    };
};

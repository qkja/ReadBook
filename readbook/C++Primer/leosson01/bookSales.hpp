
//某个书店将每本售出图书的书名和出版社输入到一个文件中,这些信息以书售出的时间顺序输入.
//每两周店主将手工计算每本书的销售量以及每个出版社的销售量报表以出版社名称的字母顺序排列以使下订单

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstring>


#define SPE " "
#define LEN strlen(SPE)


class BookSales 
{
  public:
  BookSales(const std::string& src, const std::string& dest)
    :_file_name(src)
     ,_result_name(dest)
  {}

  public:
  void run()
  {
    readFile();
    calculateSales();
    sortSales();
    result();
  }

  private:
  // 1. 读销售记录
  void readFile()
  {
    // 我们的格式应该是 书名 出版社 年-月-日\r\n 
    std::ifstream read_file(_file_name);
    if(read_file.is_open() == false)
    {
      std::cerr << "文件不存在" <<std::endl;
      return;
    }
    std::string str;
    while(std::getline(read_file, str))
    {
      _sales_records.push_back(std::move(str));
    }
  }

  // 2. 根据书名和出版社计算销售量
  void calculateSales()
  {
    // 这个我们按照
    // 书名 出版社 销售量来
    for(auto& e: _sales_records)
    {
      std::string name;
      std::string publishing_house;
      
      std::size_t pos1 = e.find(SPE, 0);
      if(pos1 == std::string::npos)
        continue;
      std::size_t pos2 = e.find(SPE, pos1+LEN);
      if(pos2 == std::string::npos)
        continue;
      name = e.substr(0, pos1);
      publishing_house = e.substr(pos1+LEN, pos2-pos1-LEN);
      
      std::unordered_map<std::string, int>& m =  _map[publishing_house];
      m[name]++;
    }
  }
  

  // 3. 以出版社名称对书名进行排序
  void sortSales()
  {
    // 注意,我们使用是map,底层是二叉树,已经排好序了,我不知道要不要对销量经行排序,不过
    // 我感觉排好序更加好一线,这里我们来直接排序一下,这里我们继续使用一个map,只不过这里我们让销量做K
    
    for(auto& p:_map)
    {
     auto& it =  _result[p.first];
     auto iter = p.second.begin();
     while(iter != p.second.end())
     {
       it.insert(std::make_pair(iter->second, iter->first));// 销量:书名
       iter++;
     }
    }
  }

  // 4 . 输出结果
  void result()
  {
    // 这里是输出结果,我们把输出的记过放在一个文件中
    std::ofstream outfile(_result_name);
    if(outfile.is_open() == false)
    {
      std::cerr << "打开文件失败" << std::endl;
      return;
    }
    for(auto& p: _result)
    {
      std::string str = p.first;
      str += SPE;
      auto iter = p.second.begin();
      while(iter != p.second.end())
      {
        std::string s = str;
        s += iter->second;
        s += SPE;
        s += std::to_string(iter->first);
        s += "\r\n";
        outfile << std::move(s);
        iter++;
      }
    }
  }

  private:
    std::string _file_name; // 这个是我们保存销售文件的名字
    std::string _result_name;
    std::vector<std::string> _sales_records; // 每一条销售记录 
    std::map<std::string, std::unordered_map<std::string, int>> _map; // 这个是计算销量
    std::map<std::string, std::multimap<int, std::string>> _result; // 这个是计算销量

};

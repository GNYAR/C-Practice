#include <iostream>
#include <regex>

using namespace std;

int main()
{
  string id;
  while (cin >> id)
  {
    regex reg("[A-Z][1-2]\\d{8}");
    if (!regex_match(id, reg))
    {
      cout << "無效" << endl;
      continue;
    }

    string s26 = "ABCDEFGHJKLMNPQRSTUVXYWZIO";
    int x = s26.find(id[0]) + 10;
    int sum = (x / 10) + (x % 10) * 9;
    for (int i = 1; i < 10; i++)
      sum += (int(id[i]) - 48) * (i != 9 ? 9 - i : 1);

    if (sum % 10)
    {
      cout << "無效" << endl;
      continue;
    }

    switch (id[0])
    {
    case 'A':
      cout << "台北市";
      break;
    case 'B':
      cout << "台中市";
      break;
    case 'C':
      cout << "基隆市";
      break;
    case 'D':
      cout << "台南市";
      break;
    case 'E':
      cout << "高雄市";
      break;
    case 'F':
      cout << "台北縣";
      break;
    case 'G':
      cout << "宜蘭縣";
      break;
    case 'H':
      cout << "桃園縣";
      break;
    case 'I':
      cout << "嘉義市";
      break;
    case 'J':
      cout << "新竹縣";
      break;
    case 'K':
      cout << "苗栗縣";
      break;
    case 'L':
      cout << "台中縣";
      break;
    case 'M':
      cout << "南投縣";
      break;
    case 'N':
      cout << "彰化縣";
      break;
    case 'O':
      cout << "新竹市";
      break;
    case 'P':
      cout << "雲林縣";
      break;
    case 'Q':
      cout << "嘉義縣";
      break;
    case 'R':
      cout << "台南縣";
      break;
    case 'S':
      cout << "高雄縣";
      break;
    case 'T':
      cout << "屏東縣";
      break;
    case 'U':
      cout << "花蓮縣";
      break;
    case 'V':
      cout << "台東縣";
      break;
    case 'W':
      cout << "金門縣";
      break;
    case 'X':
      cout << "澎湖縣";
      break;
    case 'Y':
      cout << "陽明山";
      break;
    case 'Z':
      cout << "連江縣";
      break;

    default:
      break;
    }
    cout << ' ' << (id[1] == '1' ? "男性" : "女性") << endl;
  }

  return 0;
}

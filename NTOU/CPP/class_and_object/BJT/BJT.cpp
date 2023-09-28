#include <iostream>
#include <iomanip>

using namespace std;

class active_region
{
protected:
  double VBB, VCC, VBE, RB, RC, Beta;

public:
  virtual void DC_analysis();
};

class saturation_region : public active_region
{
public:
  void DC_analysis();
};

void active_region::DC_analysis()
{
  cin >> VBB >> VCC >> VBE >> RB >> RC >> Beta;
  float ib = (VBB - VBE) / RB;
  float ic = Beta * ib;
  cout << fixed << setprecision(2);
  cout << ic << " " << ib << " ";
  cout << (1 + Beta) * ib << " ";
  cout << VCC - ic * RC << endl;
}

void saturation_region::DC_analysis()
{
  cin >> VBB >> VCC >> VBE >> RB >> RC >> Beta;
  float vce = 0.2;
  float ic = (VCC - vce) / RC;
  float ib = (VBB - VBE) / RB;
  cout << fixed << setprecision(2);
  cout << ic << " " << ib << " ";
  cout << ic + ib << " " << vce << endl;
}

int main()
{
  bool region;
  cin >> region;
  active_region *ptr = (region == true ? new active_region : new saturation_region);
  ptr->DC_analysis();
}

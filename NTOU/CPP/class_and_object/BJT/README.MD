# BJT

雙極性接面型電晶體(BJT)常被用來構成放大器電路、電動機等設備

請用 C++ 實作 BJT 共射極電路的直流分析，根據 BJT 在主動區(active region)或飽和區(saturation region)，計算的方法也不同，已知 `V_BB`, `V_CC`, `V_BE`, `R_B`, `R_C`, `β`，求 `I_C`, `I_B`, `I_E`, `V_CE`

- 主動區(active region)

  `I_B = (V_BB - V_BE) / R_B`

  `I_C = β * I_B`

  `I_E = (1 + β) * I_B`

  `V_CE = VCC - (I_C * R_C)`

- 飽和區(saturation region)

  `V_CE = 0.2`

  `I_C = (V_CC - V_CE) / R_C`

  `I_B = (V_BB - V_BE) / R_B`

  `I_E = I_C + I_B`

> 此題 BJT 只會在主動區或飽和區

電壓單位為 V，R 電阻單位為 KΩ，I 電流單位為 mA

請完成下方程式碼 `active_region::DC_analysis()`, `saturation_region::DC_analysis()` (包含計算及輸出結果)

```cpp
#include <iostream>
#include<iomanip>

using namespace std;

class active_region{
	protected:
		double VBB, VCC, VBE, RB, RC, Beta;
	public:
		virtual	void DC_analysis();
};

class saturation_region: public active_region{
	public:
		void DC_analysis();
};

void active_region::DC_analysis()
{
/*----實作部分----*/
}

void saturation_region::DC_analysis()
{
/*----實作部分----*/
}

int main(){
	bool region;
	cin >> region;
	active_region *ptr = (region == true ? new active_region : new saturation_region);
	ptr -> DC_analysis();
}
```

## Input

第一行有一個數，若為 1 則屬於主動區、0 則屬於飽和區。

第二行包含 6 個數值，分別為 `V_BB`, `V_CC`, `V_BE`, `R_B`, `R_C`, `β`，每個數之間用空格隔開。

## Output

輸出 `I_C`, `I_B`, `I_E`, `V_CE` 的值，每個值之間用空格隔開。輸出結果用四捨五入取小數點第二位。

## Sample

Input

```
1
5.7 10 0.7 200 1 200
```

Output

```
5.00 0.03 5.03 5.00
```

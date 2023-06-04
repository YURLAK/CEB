//By YURLAK SUN,2023/5/28
//此项目名为CEB（Chemical Equation Balancer），即化学式配平工具 
#include <iostream>
#include <algorithm>
#include <cmath>
//导入模块 
using namespace std;
string ele[51][2];//element,一个存元素的数组，包括其化学中英文名字 
int hhj[51];//element数组每个元素所对应的化合价，用于配平 
string xf,yf;//分别为要配平的两个化学元素 
int a,b,c;//a记录第1个元素的化合价，b记录第2个元素的化合价，c暂存查到的元素的序号 
void balancer(){
	bool kha=false,khb=false;//kha和khb代表要配平的两个化学元素是否是酸根（如果是那么要加括号）
	bool khf=false,khs=false,s=false;//khf和khs代表是否检索到两个化学元素 ,s代表是否能检索到要查询的元素 
	cout<<"输入元素（空格隔开）：";
	cin>>xf>>yf;
	if(xf=="s"){
		if(yf=="e"){
			cout<<"EXIT!";//s e代表退出 
			exit(0);//退出 
		}
		else{
			for(int i=0;i<=37;i++){
				if(yf==ele[i][0]){
					cout<<ele[i][1];c=i;s=true; 
				}
				else if(yf==ele[i][1]){
					cout<<ele[i][0];c=i;s=true;
				}
			}//查询所要搜索的元素 
			if(s==false){
				cout<<"未检索元素！"<<endl;balancer(); 
			}else{
				cout<<" ";
				if(hhj[c]>=0) cout<<"+";
				cout<<hhj[c]<<"价"<<endl; 
				balancer();
			}//若搜索到那么输出此元素化合价 
		}
	}
	for(int i=0;i<=37;i++){
		if(xf==ele[i][0]||xf==ele[i][1]){
			khf=true;//搜到第一个元素 
			if(i>=25) kha=true;//元素是酸根 
			a=hhj[i];
			xf=ele[i][0];//统一两个元素为其英文名 
		}
		if(yf==ele[i][0]||yf==ele[i][1]){
			khs=true;//搜到第二个元素 
			if(i>=25) khb=true;//元素是酸根 
			b=hhj[i];
			yf=ele[i][0];//统一两个元素为其英文名 
		}
	}
	
	if(khf==false&&khs==true){
		cout<<"未检索到元素1"<<endl;
		balancer();
	}else if(khs==false&&khf==true){
		cout<<"未检索到元素2"<<endl;
		balancer();
	}else if(khs==false&&khf==false){
		cout<<"未检索两个元素"<<endl;
		balancer();
	}
	
	if(abs(a)==abs(b)){
		cout<<xf<<" "<<yf<<endl;
		balancer();//如果化合价相加为零，直接输出，不需要配平 
	}else{
		int LCM=abs(a)*abs(b)/__gcd(abs(a),abs(b));//求两元素化合价最小公倍数
		int LCMa=LCM/abs(a);int LCMb=LCM/abs(b);//根据最小公倍数求出两元素对应的系数 
		//cout<<LCMa<<" "<<LCMb<<endl;//测试 
		if(kha==true&&LCMa!=1) cout<<"(";//若是酸根那么加括号 
		cout<<xf;
		if(kha==true&&LCMa!=1) cout<<")";//若是酸根那么加括号 
		if(LCMa!=1) cout<<LCMa;
		
		cout<<" ";
		
		if(khb==true&&LCMb!=1) cout<<"(";//若是酸根那么加括号 
		cout<<yf;
		if(khb==true&&LCMb!=1) cout<<")";//若是酸根那么加括号 
		if(LCMb!=1) cout<<LCMb;
		cout<<endl;
		balancer();
	}
}
void def(){
	//定义元素及其化合价 
	//单质 
	ele[0][0]="H";ele[0][1]="氢";hhj[0]=1;
	ele[1][0]="He";ele[1][1]="氦";hhj[1]=0;
	ele[2][0]="Li";ele[2][1]="锂";hhj[2]=1;
	ele[3][0]="Be";ele[3][1]="铍";hhj[3]=2;
	ele[4][0]="B";ele[4][1]="硼";hhj[4]=3;
	ele[5][0]="C";ele[5][1]="碳";hhj[5]=2;
	ele[6][0]="N";ele[6][1]="氮";hhj[6]=-3;
	ele[7][0]="O";ele[7][1]="氧";hhj[7]=-2;
	ele[8][0]="F";ele[8][1]="氟";hhj[8]=-1;
	ele[9][0]="Ne";ele[9][1]="氖";hhj[9]=0;
	ele[10][0]="Na";ele[10][1]="钠";hhj[10]=1;
	ele[11][0]="Mg";ele[11][1]="镁";hhj[11]=2;
	ele[12][0]="Al";ele[12][1]="铝";hhj[12]=3;
	ele[13][0]="Si";ele[13][1]="硅";hhj[13]=2;
	ele[14][0]="P";ele[14][1]="磷";hhj[14]=-3;
	ele[15][0]="S";ele[15][1]="硫";hhj[15]=-2;
	ele[16][0]="Cl";ele[16][1]="氯";hhj[16]=-1;
	ele[17][0]="Ar";ele[17][1]="氩";hhj[17]=0;
	ele[18][0]="K";ele[18][1]="钾";hhj[18]=1;
	ele[19][0]="Ca";ele[19][1]="钙";hhj[19]=2;
	ele[20][0]="Zn";ele[20][1]="锌";hhj[20]=2;
	ele[21][0]="Fe";ele[21][1]="铁";hhj[21]=3;
	ele[22][0]="Sn";ele[22][1]="锡";hhj[22]=4;
	ele[23][0]="Ba";ele[23][1]="钡";hhj[23]=2;
	ele[24][0]="Cu";ele[24][1]="铜";hhj[24]=2;
	//酸根 
	ele[25][0]="CO3";ele[25][1]="碳酸根";hhj[25]=-2;
	ele[26][0]="OH";ele[26][1]="氢氧根";hhj[26]=-1;
	ele[27][0]="SO4";ele[27][1]="硫酸根";hhj[27]=-2;
	ele[28][0]="NH4";ele[28][1]="铵根";hhj[28]=1;
	ele[29][0]="NO3";ele[29][1]="硝酸根";hhj[29]=-1;
	ele[30][0]="SO3";ele[30][1]="亚硫酸根";hhj[30]=-2;
	ele[31][0]="ClO3";ele[31][1]="氯酸根";hhj[31]=-1;
	ele[32][0]="ClO";ele[32][1]="次氯酸根";hhj[32]=-1;
	ele[33][0]="HCO3";ele[33][1]="碳酸氢根";hhj[33]=-1; 
	ele[34][0]="PO4";ele[34][1]="磷酸根";hhj[34]=-3;
	ele[35][0]="HPO4";ele[35][1]="磷酸氢根";hhj[35]=-2;
	ele[36][0]="MnO4";ele[36][1]="高锰酸根";hhj[36]=-1;
	ele[37][0]="NO2";ele[37][1]="亚硝酸根";hhj[37]=-1;
}
int main(){ 
	cout<<"-------CEB化学配平工具-------"<<endl;
	def();
	balancer();
	return 0;
}




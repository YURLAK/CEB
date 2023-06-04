//By �����,2023/5/28
//����Ŀ��ΪCEB��Chemical Equation Balancer��������ѧʽ��ƽ���� 
#include <iostream>
#include <algorithm>
#include <cmath>
//����ģ�� 
using namespace std;
string ele[51][2];//element,һ����Ԫ�ص����飬�����仯ѧ��Ӣ������ 
int hhj[51];//element����ÿ��Ԫ������Ӧ�Ļ��ϼۣ�������ƽ 
string xf,yf;//�ֱ�ΪҪ��ƽ��������ѧԪ�� 
int a,b,c;//a��¼��1��Ԫ�صĻ��ϼۣ�b��¼��2��Ԫ�صĻ��ϼۣ�c�ݴ�鵽��Ԫ�ص���� 
void balancer(){
	bool kha=false,khb=false;//kha��khb����Ҫ��ƽ��������ѧԪ���Ƿ���������������ôҪ�����ţ�
	bool khf=false,khs=false,s=false;//khf��khs�����Ƿ������������ѧԪ�� ,s�����Ƿ��ܼ�����Ҫ��ѯ��Ԫ�� 
	cout<<"����Ԫ�أ��ո��������";
	cin>>xf>>yf;
	if(xf=="s"){
		if(yf=="e"){
			cout<<"EXIT!";//s e�����˳� 
			exit(0);//�˳� 
		}
		else{
			for(int i=0;i<=37;i++){
				if(yf==ele[i][0]){
					cout<<ele[i][1];c=i;s=true; 
				}
				else if(yf==ele[i][1]){
					cout<<ele[i][0];c=i;s=true;
				}
			}//��ѯ��Ҫ������Ԫ�� 
			if(s==false){
				cout<<"δ����Ԫ�أ�"<<endl;balancer(); 
			}else{
				cout<<" ";
				if(hhj[c]>=0) cout<<"+";
				cout<<hhj[c]<<"��"<<endl; 
				balancer();
			}//����������ô�����Ԫ�ػ��ϼ� 
		}
	}
	for(int i=0;i<=37;i++){
		if(xf==ele[i][0]||xf==ele[i][1]){
			khf=true;//�ѵ���һ��Ԫ�� 
			if(i>=25) kha=true;//Ԫ������� 
			a=hhj[i];
			xf=ele[i][0];//ͳһ����Ԫ��Ϊ��Ӣ���� 
		}
		if(yf==ele[i][0]||yf==ele[i][1]){
			khs=true;//�ѵ��ڶ���Ԫ�� 
			if(i>=25) khb=true;//Ԫ������� 
			b=hhj[i];
			yf=ele[i][0];//ͳһ����Ԫ��Ϊ��Ӣ���� 
		}
	}
	
	if(khf==false&&khs==true){
		cout<<"δ������Ԫ��1"<<endl;
		balancer();
	}else if(khs==false&&khf==true){
		cout<<"δ������Ԫ��2"<<endl;
		balancer();
	}else if(khs==false&&khf==false){
		cout<<"δ��������Ԫ��"<<endl;
		balancer();
	}
	
	if(abs(a)==abs(b)){
		cout<<xf<<" "<<yf<<endl;
		balancer();//������ϼ����Ϊ�㣬ֱ�����������Ҫ��ƽ 
	}else{
		int LCM=abs(a)*abs(b)/__gcd(abs(a),abs(b));//����Ԫ�ػ��ϼ���С������
		int LCMa=LCM/abs(a);int LCMb=LCM/abs(b);//������С�����������Ԫ�ض�Ӧ��ϵ�� 
		//cout<<LCMa<<" "<<LCMb<<endl;//���� 
		if(kha==true&&LCMa!=1) cout<<"(";//���������ô������ 
		cout<<xf;
		if(kha==true&&LCMa!=1) cout<<")";//���������ô������ 
		if(LCMa!=1) cout<<LCMa;
		
		cout<<" ";
		
		if(khb==true&&LCMb!=1) cout<<"(";//���������ô������ 
		cout<<yf;
		if(khb==true&&LCMb!=1) cout<<")";//���������ô������ 
		if(LCMb!=1) cout<<LCMb;
		cout<<endl;
		balancer();
	}
}
void def(){
	//����Ԫ�ؼ��仯�ϼ� 
	//���� 
	ele[0][0]="H";ele[0][1]="��";hhj[0]=1;
	ele[1][0]="He";ele[1][1]="��";hhj[1]=0;
	ele[2][0]="Li";ele[2][1]="�";hhj[2]=1;
	ele[3][0]="Be";ele[3][1]="��";hhj[3]=2;
	ele[4][0]="B";ele[4][1]="��";hhj[4]=3;
	ele[5][0]="C";ele[5][1]="̼";hhj[5]=2;
	ele[6][0]="N";ele[6][1]="��";hhj[6]=-3;
	ele[7][0]="O";ele[7][1]="��";hhj[7]=-2;
	ele[8][0]="F";ele[8][1]="��";hhj[8]=-1;
	ele[9][0]="Ne";ele[9][1]="��";hhj[9]=0;
	ele[10][0]="Na";ele[10][1]="��";hhj[10]=1;
	ele[11][0]="Mg";ele[11][1]="þ";hhj[11]=2;
	ele[12][0]="Al";ele[12][1]="��";hhj[12]=3;
	ele[13][0]="Si";ele[13][1]="��";hhj[13]=2;
	ele[14][0]="P";ele[14][1]="��";hhj[14]=-3;
	ele[15][0]="S";ele[15][1]="��";hhj[15]=-2;
	ele[16][0]="Cl";ele[16][1]="��";hhj[16]=-1;
	ele[17][0]="Ar";ele[17][1]="�";hhj[17]=0;
	ele[18][0]="K";ele[18][1]="��";hhj[18]=1;
	ele[19][0]="Ca";ele[19][1]="��";hhj[19]=2;
	ele[20][0]="Zn";ele[20][1]="п";hhj[20]=2;
	ele[21][0]="Fe";ele[21][1]="��";hhj[21]=3;
	ele[22][0]="Sn";ele[22][1]="��";hhj[22]=4;
	ele[23][0]="Ba";ele[23][1]="��";hhj[23]=2;
	ele[24][0]="Cu";ele[24][1]="ͭ";hhj[24]=2;
	//��� 
	ele[25][0]="CO3";ele[25][1]="̼���";hhj[25]=-2;
	ele[26][0]="OH";ele[26][1]="������";hhj[26]=-1;
	ele[27][0]="SO4";ele[27][1]="�����";hhj[27]=-2;
	ele[28][0]="NH4";ele[28][1]="笠�";hhj[28]=1;
	ele[29][0]="NO3";ele[29][1]="�����";hhj[29]=-1;
	ele[30][0]="SO3";ele[30][1]="�������";hhj[30]=-2;
	ele[31][0]="ClO3";ele[31][1]="�����";hhj[31]=-1;
	ele[32][0]="ClO";ele[32][1]="�������";hhj[32]=-1;
	ele[33][0]="HCO3";ele[33][1]="̼�����";hhj[33]=-1; 
	ele[34][0]="PO4";ele[34][1]="�����";hhj[34]=-3;
	ele[35][0]="HPO4";ele[35][1]="�������";hhj[35]=-2;
	ele[36][0]="MnO4";ele[36][1]="�������";hhj[36]=-1;
	ele[37][0]="NO2";ele[37][1]="�������";hhj[37]=-1;
}
int main(){ 
	cout<<"-------CEB��ѧ��ƽ����-------"<<endl;
	def();
	balancer();
	return 0;
}




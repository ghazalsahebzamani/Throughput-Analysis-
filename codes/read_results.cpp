#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

void write_to_file(const char* in,const char* out){
	string line;
	string size="";
	int size_num;
	ifstream myfile;
	ofstream outfile;
	outfile.open(out);
	vector<int> tput(5,0);
	myfile.open(in);
    while ( getline (myfile,line) )
        {
          	if  (line[0]=='r')
          	{
              for(int i=0;i<line.size();i++)
             {
             	
             	if(i+14 < line.size() && line.substr(i,14)=="Payload (size=")
             	{
             		for(int j=i+14;line[j]!=')';j++)
             		{
             			size.push_back(line[j]);
             	

             		}
             		size_num=atoi(size.c_str());
             		
             		size="";
             		if(size_num==1024)
             		{
             			for(int i=0;i<line.size();i++)
             			{
             				if(i+10<line.size()  && line.substr(i,10)=="/NodeList/")
             				{
             					int a=line[i+10]-48;
             					if( a>=3 && a<=7)
             					tput[a-3]++;
             					break;

             				}
             			}
             		}

             	}



             }
            }  
        }
        for(int i=0;i<tput.size();i++)
        	outfile<<tput[i]*1024<<" ";
  }

  int main()
{
	write_to_file("results1.tr","out1.txt");
	write_to_file("results2.tr","out2.txt");
	write_to_file("results3.tr","out3.txt");
	write_to_file("results4.tr","out4.txt");
	write_to_file("results5.tr","out5.txt");
	write_to_file("results6.tr","out6.txt");

}



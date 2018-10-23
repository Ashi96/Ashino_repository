#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
#define Name_A "city011"
#define Name_B "city012"

class voice_data
{
	private:
		char filename_t[101][20];
		char file_name_t[101][25];
		char speak_t[101][20];
		int row_t[101][2];
		double data_t[150][16];
		char filename_n[101][20];
		char file_name_n[101][25];
		char speak_n[101][20];
		int row_n[101][2];
		double data_n[150][16];
		double d[150][16];
	public:
		char read_textfile();
};

char voice_data::read_textfile()
{
	FILE* fp1;
	for(int file_num_t = 1; file_num_t < 101; file_num_t++){
		sprintf(file_name_t[file_num_t],"%s/%s_%03d.txt",Name_A,Name_A,file_num_t);
		cout << file_name_t[file_num_t] << '\n';
		//fp1 = fopen("city011/city011_001.txt","r");
		fp1 = fopen(file_name_t[file_num_t],"r");
		if(fp1 == NULL){
			cout << '"' << file_name_t[file_num_t] << "' cant open!!\n";
		}else{
			cout << '"' << file_name_t[file_num_t] << "' can open!!\n";
		}
		fgets(filename_t[file_num_t],15,fp1);
		cout << filename_t[file_num_t];
		fgets(speak_t[file_num_t],10,fp1);
		cout << speak_t[file_num_t] << '\n';
		fscanf(fp1,"%d",&row_t[file_num_t][1]);
		cout << row_t[file_num_t][1] << '\n';
		for(int j = 1; j <= row_t[file_num_t][1]; j++){
			cout << j << ':';
			for(int k = 1; k < 16; k++){
				fscanf(fp1,"%lf,",&data_t[j][k]);
				cout << data_t[j][k] << ',';
			}
			cout << '\n';
		}
		fclose(fp1);
	}
	int frame_n[151][2];
	FILE* fp2;
	for(int file_num = 1; file_num < 101; file_num++){
		sprintf(file_name_n[file_num],"%s/%s_%03d.txt",Name_B,Name_B,file_num);
		cout << file_name_n[file_num] << '\n';
		//fp1 = fopen("city011/city011_001.txt","r");
		fp2 = fopen(file_name_n[file_num],"r");
		if(fp2 == NULL){
			cout << '"' << file_name_n[file_num] << "' cant open!!\n";
		}else{
			cout << '"' << file_name_n[file_num] << "' can open!!\n";
		}
		fgets(filename_n[file_num],15,fp2);
		cout << filename_n[file_num];
		fgets(speak_n[file_num],10,fp2);
		cout << speak_n[file_num] << '\n';
		fscanf(fp2,"%d",&row_n[file_num][1]);
		cout << row_n[file_num][1] << '\n';
		for(int j = 1; j <= row_n[file_num][1]; j++){
			cout << j << ':';
			for(int k = 1; k < 16; k++){
				fscanf(fp2,"%lf,",&data_n[j][k]);
				cout << data_n[j][k] << ',';
			}
			cout << '\n';
			//frame_n[file_num][1] = j;
		}
		frame_n[file_num][1] = j;
		fclose(fp2);
	}
	for(int jj = 0;jj < 101; jj++)
		cout << frame_n[jj][1] << '\n';
}

/*char voice_data::read_textfile(int choice)
{
	FILE* fp1;
	for(int file_num = 1; file_num < 101; file_num++){
		if(choice == 0){
			sprintf(file_name[file_num],"%s/%s_%03d.txt",Name_A,Name_A,file_num);
		}else{
			sprintf(file_name[file_num],"%s/%s_%03d.txt",Name_B,Name_B,file_num);
		}
		cout << file_name[file_num] << '\n';
		//fp1 = fopen("city011/city011_001.txt","r");
		fp1 = fopen(file_name[file_num],"r");
		if(fp1 == NULL){
			cout << '"' << file_name[file_num] << "' cant open!!\n";
		}else{
			cout << '"' << file_name[file_num] << "' can open!!\n";
		}
		fgets(filename[file_num],15,fp1);
		cout << filename[file_num];
		fgets(speak[file_num],10,fp1);
		cout << speak[file_num] << '\n';
		fscanf(fp1,"%d",&row[file_num][1]);
		cout << row[file_num][1] << '\n';
		for(int j = 1; j <= row[file_num][1]; j++){
			cout << j << ':';
			for(int k = 1; k < 16; k++){
				fscanf(fp1,"%lf,",&data[j][k]);
				cout << data[j][k] << ',';
			}
			cout << '\n';
		}
		fclose(fp1);
	}
}*/

int main()
{
	voice_data dp;
	dp.read_textfile();
}

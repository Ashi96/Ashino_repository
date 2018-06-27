// リニアレールの倒立プログラム(PID制御version)

#include "mbed.h"
#include "Motor.h"
#include "QEI.h"

BusOut led(LED1, LED2, LED3, LED4);						//基板LED用IO設定
AnalogIn pen1(xp15);										//ポテンショメータ１用IO設定
AnalogIn pen2(xp16);										//ポテンショメータ２用IO設定
BusIn sw(SW1);

Ticker pen_control;
Ticker extra_control;										//台車の速度制御用タイマー割り込み
Serial pc(USBTX, USBRX);								//デバッグ用シリアル通信

//モータ制御用オブジェクト
Motor motor_left(MOTOR1_IN1, MOTOR1_IN2, MOTOR1_PWM);	//左モータ
Motor motor_right(MOTOR2_IN1, MOTOR2_IN2, MOTOR2_PWM);	//右モータ

//***************　台車の速度制御　ここから　***************//
//**定数**//
int TARGET_THETA = 777;									//振子の目標値(AD値)
int EXTRA_THETA = 0;
double kp = 0.9;										
double ki = 0.7;
double kd = 0.2;
double T = 0.001;
double possible_theta = 60;
double ex_possible_theta = 300;
//**変数**//
int adv,adv1,adv2;										//振子についているポテンショメータのAD値格納用
double speed;											//車体の速度
double e0 = 0;											
double ei = 0;
double e;
double ed;
double raise_up_speed;

void pen_control_handler(){
	adv1 = pen1.read_u16()>>6;							//ADCを通してポテンショメータ1のAD値を取得
	adv = adv1;

	ea = (double)(TARGET_THETA - adv);
	if(ea < 0) ea = -ea;

	if(ea < possible_theta){
		e = (double)(TARGET_THETA - adv);			//振子の目標値とポテンショメータのAD値の差分を計算して格納
		ed = (e - e0) / T;
		ei += ( e * T);
		e0 = e;
		speed = (int)(e * kp + ei * ki + ed * kd);			//PID制御
	}else{
		motor_left = motor_right = 0;
		return;
	}

	//速度指令値の頭打ち処理
	if(speed > 1.0) speed = 1.0;
	if(speed < -1.0) speed = -1.0;
	
	//**** 速度指令値によって発行するLEDを変える ****//
		if(speed > 0.8 ){
			led = 8;
		}else if(speed <= 0.8 && speed >= 0){
			led = 4;
		}else if(speed < 0 && speed >= -0.8){
			led = 2;
		}else if(speed < -0.8){
			led = 1;
		}
	
	//計算結果をモータの速度指令に反映
	motor_left = speed;
	motor_right = speed;

}

void extra_control_handler(){
	adv2 = pen2.read_u16()>>6;							//ADCを通してポテンショメータ2のAD値を取得
	
	adv = adv1;
	
	e = (double)(EXTRA_THETA - adv);			//振子の目標値とポテンショメータのAD値の差分を計算して格納
	if(e < 0) e = -e;

	if(e < ex_possible_theta)return;

	if((theta < EXTRA_THETA) && (e < e0) raise_up_speed;
	else if((theta < EXTRA_THETA) && (e > e0)) raise_up_speed = -raise_up_speed;
	else if((theta > EXTRA_THETA) && (e < e0)) raise_up_speed = -raise_up_speed;
	else raise_ip_speed;
	speed = raise_up_speed;

	//速度指令値の頭打ち処理
	if(speed > 1.0) speed = 1.0;
	if(speed < -1.0) speed = -1.0;
	
	//**** 速度指令値によって発行するLEDを変える ****//
		if(speed > 0.8 ){
			led = 8;
		}else if(speed <= 0.8 && speed >= 0){
			led = 4;
		}else if(speed < 0 && speed >= -0.8){
			led = 2;
		}else if(speed < -0.8){
			led = 1;
		}
	
	//計算結果をモータの速度指令に反映
	motor_left = speed;
	motor_right = speed;

}

//***************　main関数　ここから　***************//
int main() {
	sw.mode(PullUp);
	
	//モータの最大速度を設定
	motor_left.setMaxRatio(0.9);
	motor_right.setMaxRatio(0.9);

	while(1){
		if(sw == 1){
			extra_control.attach(&extra_control_handler, T);
		}else{
			pen_control.attach(&pen_control_handler, T);		//台車の速度制御用のタイマー関数を設定	
		}

	led = 1;		//LEDの値を設定　動作確認用
	
	wait(1.0);		//なんとなく1秒待つ
	
	while(1) {		//無限ループ

		if(pc.getc() == 'a'){
			kp += 0.01;
		}else if(pc.getc() == 'b'){
			kp -= 0.01;
		}
		if(pc.getc() == 'c'){
		ki += 0.01;
		}else if(pc.getc() == 'd'){
			ki -= 0.01;
		}
		if(pc.getc() == 'e'){
		kd += 0.01;
		}else if(pc.getc() == 'f'){
			kd -= 0.01;
		}
	}
	while(1){
		printf("adv:%d pen_theta:%f[rad] speed:%2.2f\r\n",adv,theta,speed);
		wait(0.1);
	}
}


#ifndef UNIT_CPP
#define UNIT_CPP

#include <vector>
#include "header/objects.h"
#include "header/unit.h"
#include <iostream>
#include <cmath>

//5-knight  6-pleasant 7-ram



void unit::move(){
    int gag=un.size()-1;
    
    for(int i=0;i<(int) un.size()-gag;i++)
     {
        if((int) un[i].pos>=(int) roadV.size()){
            un[i].pos=-2;
            gag--;
        } else
        if ( fabs(un[i].pos+1)==0) un[i].pos=0;
        else
        if ( fabs(un[i].pos+2)!=0) un[i].pos+= (float) un[i].speed*dtime;
        else
        if((int) un[i].pos>=(int) roadV.size()){
            un[i].pos=-2;
            gag--;
        }
        if (un[i].pos>=1 || fabs(un[i].pos+2)==0) 
            gag--;
    }
    
    for(int i=0;i<(int) un.size();i++){
        cout<<"un["<<i<<"].pos=" <<un[i].pos<<endl;
    }

}

void unit::default_value(){
    
    float def_speed=1.7; //вдруг потом скорость передавать через "более ранние" классы?
    for(int i=0; i<attack.size();i++){
        un.push_back(par_str());
        switch (attack[i]){
            case 5: 
            un[i].speed=(float) def_speed*0.80;
            un[i].health=15;
            break;
            case 6:
            un[i].speed=(float) def_speed*1;
            un[i].health=10;
            break;
            case 7:
            un[i].speed=(float) def_speed*0.45;
            un[i].health=28;
            break;
        }
        un[i].pos=-1;

    }
    un[0].pos=0.0;

}



void unit::road(){
    cout<< endl<< endl;
    for(int y=0; y<F_Y;y++)
        for(int x=0; x<F_X;x++){
            if( nf(x,y)==8){
                roadV.push_back( F_X*y+(F_X-x-1) );
            }
            cout<< endl;
        }
    for(int i=0; i<roadV.size();i++)
        cout<<"roadV["<<i<<"]="<<roadV[i]<<endl;
}

unit::unit(vector<int> fields_in,vector<int> attack_in,objects  OBJ_in, int F_X, int F_Y, double time)
:fields(fields_in),attack(attack_in),  OBJ(OBJ_in), F_X(F_X), F_Y(F_Y), old_time(time) {
        empty=true;
        cout<< "!!!!!!empty="<<empty;
        default_value(); //Заполняет UN из attack
        road();          //Заполняет length

}

int unit::nf(int X, int Y){
    cout<<"x="<<X<<", y="<<Y<<", NN="<<fields[F_X*Y+(F_X-X-1)]<< endl;
    return ( fields[F_X*Y+(F_X-X-1)] );
}

void unit::calc(double in_time){
    time=in_time;
    dtime=time-old_time;
    //getDamage();
    move();
    old_time=time;
}

int unit::convert(int num){
    return F_X*F_Y-num-1;
}


float unit::getVecX(int num){  
    int g=(int) un[num].pos;
    float drobn=(float) un[num].pos-g;
    cout<<endl<<"xx"<< (int) un[num].pos << un[num].pos <<"WOW"<< endl;;
    cout << "vecX("<<num<<")=" <<OBJ.getVecX( convert( roadV[g+1] ) )-OBJ.getVecX( convert( roadV[g] ) )<< endl;
    return ( OBJ.getVecX( convert( roadV[g] ) )+ drobn*( OBJ.getVecX( convert( roadV[g+1] ) )-OBJ.getVecX( convert( roadV[g] ) ) ) );
}

int unit::ch(int i){

        cout<<"!!un["<<i<<"].pos=" <<un[i].pos<<endl;
    
    if ( un[i].pos<0 ) {
        cout<< un[i].pos-roadV.size() << " ;;"<< fabs(un[i].pos-roadV.size()) << ";;;"<< roadV.size()<< endl;
        cout<< "un[i]=!!!!!"<< un[i].pos <<endl;
        return 0;
    }
    else return 1;
}

float unit::getVecY(int num){   
    int g=(int) un[num].pos;
    float drobn=(float) un[num].pos-g;
    //g=g+F_X*(F_Y-)
    cout << " vecY("<<num<<")=" <<OBJ.getVecY( convert( roadV[g+1] ) )-OBJ.getVecY( convert( roadV[g] ) )<<endl;
    return    (OBJ.getVecY( convert( roadV[g] ) )+ drobn*( OBJ.getVecY( convert( roadV[g+1] ) )-OBJ.getVecY( convert( roadV[g] ) ) ) );

}



//Методы для тестов(инициализация)
void unit::testMove(){};
    
    
    
//(получение параметров)



#endif
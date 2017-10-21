#ifndef UNIT_CPP
#define UNIT_CPP

#include <vector>
#include "header/objects.h"
#include "header/unit.h"
#include "header/healthbar.h"
#include <iostream>
#include <cmath>

//5-knight  6-pleasant 7-ram
unit::unit(int *proc): process(proc) {};

void unit::move(){
    int gag=un.size()-1;
    cout<< roadV.size() <<"LOL"<< endl;
    for(int i=0;i<(int) un.size()-gag;i++)
    {
        if((int) un[i].pos>=((int) roadV.size()-1)){
            cout<< "WTF???"<< un[i].pos<<" "<<roadV.size()-1<<endl;
            un[i].pos=-2;
            gag--;
        } else
        if ( un[i].pos==-1) un[i].pos=0;
        else
        if ( un[i].pos!= -2) un[i].pos+= (float) un[i].speed*dtime;
        else
        if( un[i].pos>=(int) roadV.size()) {
            un[i].pos=-2;
            gag--;
        }
        if (un[i].pos>=1 || un[i].pos==-2) 
            gag--;
    }
    
    for(int i=0;i<(int) un.size();i++){
        cout<<"un["<<i<<"].pos=" <<un[i].pos<<endl;
    }
    

    
}

void unit::default_value(){
    
    float def_speed=1.5; //вдруг потом скорость передавать через "более ранние" классы?
    float def_heath=20;
    for(unsigned int i=0; i<attack.size();i++){
        un.push_back(par_str());
        switch (attack[i]){
            case 5: //рыцарь
            un[i].speed=(float) def_speed*0.80;
            un[i].health=15*def_heath;
            break;
            case 6: //крестьяне
            un[i].speed=(float) def_speed*1;
            un[i].health=10*def_heath;
            break;
            case 7: //таран
            un[i].speed=(float) def_speed*0.45;
            un[i].health=28*def_heath;
            break;
        }
        un[i].pos=-1;
        cout<<"!!!!un["<<i<<"]="<<un[i].health<<endl;
    }
    un[0].pos=0.0;

    float def_damage=5;
    float def_dps=1;
    float def_rad=1.4;
    for(int i=0; defence->size()-i*2>0;i++){
        def.push_back(def_str());
        switch (defence->at(i*2)){
            case 2: //лучник
            def[i].damage=(float) def_damage*0.4;
            def[i].dps=(float) def_dps*1;
            def[i].rad=(float) def_rad*0.5;
            break;
            case 3: //катапульта
            def[i].damage=(float) def_damage*1;
            def[i].dps=(float) def_dps*0.3;
            def[i].rad=(float) def_rad*1;
            break;
            case 4: //арбалетчик
            def[i].damage=(float) def_damage*0.7;
            def[i].dps=(float) def_dps*0.7;
            def[i].rad=(float) def_rad*0.6;
            break;
        }
        def[i].last_trig=def[i].rad;
    }
    default_health.push_back(15*def_heath); //5 -0
    default_health.push_back(10*def_heath); //6 -1
    default_health.push_back(28*def_heath); //7 -2

}

void unit::road(){

    for(int y=0; y<F_Y;y++)
        for(int x=0; x<F_X;x++){
            if( nf(x,y)==8){
                roadV.push_back( F_X*y+(F_X-x-1) );
            }
        }
}

void unit::in(vector<int> fields_in,vector<int> attack_in,vector<int> *defence_in, int F_X, int F_Y, double time){
        fields=fields_in;
        attack=attack_in;   
        this->F_X=F_X; 
        this->F_Y=F_Y; 
        old_time=time;
        defence=defence_in; 

        OBJ=new objects(&fields[0],F_X, F_Y);
        hb=new healthbar(OBJ->getSize_x(),OBJ->getSize_y());
        empty=true;
        default_value(); //Заполняет UN из attack
        road();          //Заполняет length

}

int unit::nf(int X, int Y){
    return ( fields[F_X*Y+(F_X-X-1)] );
}

void unit::calc(double in_time){
    time=in_time;
    dtime=time-old_time;
    move();
    getDamage();
    old_time=time;
    
}

int unit::convert(int num){
    return F_X*F_Y-num-1;
}

float unit::getVecX(int num){  
    int g=(int) un[num].pos;
    float drobn=(float) un[num].pos-g;
    return ( OBJ->getVecX( convert( roadV[g] ) )+ drobn*( OBJ->getVecX( convert( roadV[g+1] ) )-OBJ->getVecX( convert( roadV[g] ) ) ) );
}

int unit::ch(int i){

    
    if ( un[i].pos<0 ) {
        return 0;
    }
    else return 1;
}

float unit::getVecY(int num){   
    int g=(int) un[num].pos;  
    float drobn=(float) un[num].pos-g;
    return    (OBJ->getVecY( convert( roadV[g] ) )+ drobn*( OBJ->getVecY( convert( roadV[g+1] ) )-OBJ->getVecY( convert( roadV[g] ) ) ) );
}

void unit::draw(){
    OBJ->draw();
    for(int i=0;defence->size()-i*2>0;i++){
        OBJ->drawSingle(defence->at(i*2),defence->at(i*2+1));
    }
    for(unsigned int i=0;i<attack.size();i++){
        if((int) un[i].pos>=0  && un[i].pos<(int) (roadV.size()-1) && un[i].health>0){
                OBJ->drawUnit(getVecX(i),getVecY(i), attack[i]);
                drawHealthbar(i);
        }
    }
    

}

void unit::drawHealthbar(int num){
    hb->in(getVecX(num), getVecY(num), un[num].health/default_health[attack[num]-5 ] );

}

void unit::getDamage(){
    float x,y;
    live =0; 
    pos_win=0;
    for(unsigned int i=0;i<un.size();i++){
        x=getVecX(i);
        y=getVecY(i);
        for(int k=0;defence->size()-k*2>0;k++){
            float len=pow(x-OBJ->getVecX(defence->at(k*2+1)),2)+pow(y-OBJ->getVecY(defence->at(k*2+1)),2);
            //cout<<len<<" k="<<k<<" rad="<<def[k].rad<<" last="<<def[k].last_trig<<endl;
            if( len<=def[k].rad && def[k].dps<=time-def[k].last_trig && un[i].health>0){
                def[k].last_trig=time;
                un[i].health=un[i].health-def[k].damage;
            }
        }
        cout<<"un["<<i<<"]="<<un[i].health<<endl;
        if ( un[i].pos==-1 ) pos_win++;
        if ( un[i].health<=0 ) live++;
    }
    if (  live==un.size()) *process=3;
    if (  pos_win==un.size()) *process=4;
}

//Методы для тестов(инициализация)
void unit::testMove(){};
    
    
    
//(получение параметров)



#endif
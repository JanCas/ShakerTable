#include "MotorEncoder.hpp"


MotorEncoder::MotorEncoder(int ena_pin, int in1_pin, int in2_pin, int encoder_pin1, int encoder_pin2, int gear_ratio, int count){
    this->ena_pin = ena_pin;
    this->in1_pin = in1_pin;
    this->in2_pin = in2_pin;
    this->gear_ratio = gear_ratio;
    this->count = count;

    this->encoder = new Encoder(encoder_pin1, encoder_pin2);

    pinMode(this->ena_pin, OUTPUT);
    pinMode(this->in1_pin, OUTPUT);
    pinMode(this->in2_pin, OUTPUT);

    digitalWrite(this->in1_pin, HIGH);
    digitalWrite(this->in2_pin, LOW);

    this->speed = 0;
    deg_per_count =(float) (360.0 / (count*gear_ratio));
    direction_clockwise = true;
    old_pos = 0;
}

MotorEncoder::~MotorEncoder() {
    delete this->encoder;
}

void MotorEncoder::reset() {
    this->encoder->write(0);
}

void MotorEncoder::turn_on() {
    analogWrite(this->ena_pin, this->speed);
}

double MotorEncoder::set_speed(double speed) {

    if (speed < 0){
        ccw();
        speed = abs(speed);
    }else if (speed > 0){
        cw();
    }

    speed = normalize_speed(speed);

    this->speed = speed;

    analogWrite(this->ena_pin, speed);

    return speed;

}

void MotorEncoder::turn_off() {
    analogWrite(this->ena_pin, 0);
}

double MotorEncoder::normalize_speed(double speed) {
    return constrain(speed, -255., 255.);
}

void MotorEncoder::ccw(){
    if (!direction_clockwise){
        digitalWrite(this->in1_pin, LOW);
        digitalWrite(this->in2_pin, HIGH);
        direction_clockwise = true;
    }
}

void MotorEncoder::cw(){
    if (direction_clockwise){
        digitalWrite(this->in1_pin, HIGH);
        digitalWrite(this->in2_pin, LOW);
        direction_clockwise = false;
    }
}

float MotorEncoder::get_pos(){
    old_pos = deg_per_count * encoder->read();
    return old_pos;
}

bool MotorEncoder::drive_to(int des_pos){
    
    pid(des_pos);

    if(t - t_start > 1){
        turn_off();
        if (get_pos() == old_pos){
            return true;
        }
    }
    return false;
}


double MotorEncoder::set_init_speed(double speed){
    this->speed = normalize_speed(speed);
    return this->speed;
}

float MotorEncoder::get_speed(){

    // double old_pos_temp = old_pos;
    // Serial.print(old_pos);
    // Serial.print(" || ");
    // Serial.print(get_pos());
    // Serial.print(" || ");
    // Serial.print(t_old);
    // Serial.print(" || ");
    // Serial.print(millis());
    // Serial.print(" || ");
    // Serial.print(old_pos - get_pos());
    // Serial.print(" || ");
    // Serial.println((double)t_old - (double)millis());


    return (old_pos - get_pos()) / ((double)t_old - (double)millis()) * 2.778;
}

void MotorEncoder::pid(double des){
    t = millis(); // current time

    if (t > t_old + T_interval)
    {
        
        // Controller code
        delta_t = t - t_old;
        float s = get_speed();
        pos = get_pos();
        error = des - s;
        integralError = integralError + error * delta_t;
        dErrordt = (error - error_old) / delta_t;
        dErrordtFilt = dErrordt * alpha + dError_filt_old * (1 - alpha);
        V = Kp * error + Kd * dErrordtFilt + Ki * integralError;

        dError_filt_old = dErrordtFilt;
        error_old = error;
        t_old = t;
        old_pos = pos;

        V = constrain(V, -255., 255.);
        
        Serial.print(" || ");
        Serial.print(s);
        Serial.print(" || ");
        Serial.print(des);
        Serial.print(" || ");
        Serial.print(V);
        Serial.print(" || ");
        Serial.println(error);

        
        set_speed(V);
    }
}

void MotorEncoder::set_pid_values(double Kp, double Kd, double Ki, double alpha){
    this->alpha = alpha;
    this->Kp = Kp;
    this->Kd = Kd;
    this->Ki = Ki;
}
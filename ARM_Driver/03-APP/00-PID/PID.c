#include "PID.h"

void PID_init(PID_control *pid)
{
	pid->Integrator = 0.0f;
	pid->prevError  = 0;

	pid->differentiator  = 0.0f;
	pid->prevMeasurement = 0;

	pid->output = 0;

}

u32 Absolute(s32 number)
{
	if(number<0)
	{
		return (-1*(number));
	}
	else
	{
		return number;
	}
}
s32 PID_controller_calc(PID_control *pid, s32 setpoint ,s32 RT_measurment)
{
	
	s32 error;
	s32 propotional;


//if(RT_measurment>0)
//{
//	error = RT_measurment + setpoint;
//}
//else if(RT_measurment<0)
//{
//	error = RT_measurment - setpoint;
//}
//else
//{
//	return 0;
//}
	error = setpoint - RT_measurment;

	propotional= (pid->Kp)*error;

	pid -> Integrator = pid -> Integrator + 0.5f * pid->Ki * pid->Sampling_Time * (error + pid->prevError);
	/*Clamping of integrator*/
	if(pid -> Integrator > pid -> Max_Integrator_Limit )
	{
		pid -> Integrator =pid -> Max_Integrator_Limit;
	}
	else if(pid -> Integrator < pid -> Min_Integrator_Limit )
	{
		pid -> Integrator =pid -> Min_Integrator_Limit;
	}
	
	
	pid -> differentiator = -(2.0f * pid->Kd * (RT_measurment - pid->prevMeasurement)	/* Note: derivative on measurement, therefore minus sign in front of equation! */
                             + (2.0f * pid->Tau - pid->Sampling_Time) * pid->differentiator)
                             / (2.0f * pid->Tau + pid->Sampling_Time);

	
	pid -> output= propotional+ (pid -> Integrator) + (pid -> differentiator);
	
	/*clamping the output*/
	if(pid->output >pid-> Max_Limit)
	{
		pid -> output =pid -> Max_Limit;
	}
	else if(pid->output < pid->Min_Limit)
	{
		pid -> output = pid -> Min_Limit;
	}
	
	/*restoring the last error and measurement*/
	pid -> prevError =error;
	pid -> prevMeasurement= RT_measurment;
	

	return pid -> output;
}



#include "PID.h"

void PID_init(PID_control *pid)
{
	pid->Integrator = 0.0f;
	pid->prevError  = 0.0f;

	pid->differentiator  = 0.0f;
	pid->prevMeasurement = 0.0f;

	pid->output = 0.0f;

}


f32 PID_controller_calc(PID_control *pid, f32 setpoint ,f32 RT_measurment)
{
	
	f32 error;
	f32 propotional;
	
	error = RT_measurment-setpoint;
	
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


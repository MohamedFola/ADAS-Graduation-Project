#include "../../00-LIB/STD_TYPES.h"

typedef struct
{
	/*PID constants*/
	f32 Kp;
	f32 Ki;
	f32 Kd;
	
	/*Output limits*/
	s32 Max_Limit;
	s32 Min_Limit;
	
	/*Integrator Limits*/
	f32 Max_Integrator_Limit;
	f32 Min_Integrator_Limit;
	
	/*Sampling Time*/
	f32 Sampling_Time;
	
	/*Low pass Filter time constant */
	f32 Tau;
	
	/*Previous Reading*/
	s32 prevMeasurement;		/* Required for differentiator */
	s32 prevError;			/* Required for integrator */
	/*****************/
	f32 differentiator;
	f32   Integrator;

	s32 output;
}PID_control;

void PID_init(PID_control * pid );
s32 PID_controller_calc(PID_control *pid, s32 setpoint ,s32 RT_measurment);
u32 Absolute(s32 number);


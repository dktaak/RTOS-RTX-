#include<RTL.H>
#include<LPC21XX.H>

#define LED1 (1<<14)//p0.14
#define LED2 (1<<15)//p0.15
#define SW ((IOPIN0>>13)&1)//p0.13


OS_TID tid1,tid2;

__task  void task2(void)
{
	for(;;)
	{
		if(SW==0)
		 IOCLR0=LED2;//LED ON
		else
		 IOSET0=LED2;//LED OFF
	}
}
__task  void task1(void)
{
	tid2=os_tsk_create(task2,2);
	
	for(;;)
	{

		IOCLR0=LED1;//LED ON
		  os_dly_wait(100);
		IOSET0=LED1;//LED OFF
		  os_dly_wait(100);//1sec delay

	}
}

main()
{
	IODIR0=LED1|LED2;//SET GPIO PIN AS OTPUT DIRECTION
	IODIR0&=~(1<<13);
	os_sys_init(task1);
}

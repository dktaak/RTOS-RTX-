#include<RTL.H>

unsigned long int count1,count2;
OS_TID tid2;//act like descriptor to control task2 activities
OS_TID tid1;

__task void task2(void)
{
	for(;;){
		count2++;
	}
}

__task void task1(void)
{
	//tid1=os_tsk_self();
	os_tsk_create(task2,1);//will create task2 and will put in ready state ;pr=1;round robin schduling policy
	for(;;){
	count1++;
	}
}

main()
{
   os_sys_init(task1);//default pr=1
}

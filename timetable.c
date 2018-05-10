#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
/*typedef struct NODE{
	int startTime;
	int endTime;
	FACULTY 
}*/
typedef struct COURSE{
	int id;
	int credits;
	int hours;
	char name[500];
}COURSE;
typedef struct STUDENTDETAILS{
	int id;
	char name[50];
	int year;
	char batch;
	char email[60];
	COURSE *takenCourses;
	int credits;
}STUDENTDETAILS;
typedef struct STUDENT{
	STUDENTDETAILS *sd;
}STUDENT;
typedef struct FACULTY{
	int fid;
	char fname[500];
	int pos;		//Professor,Assistant Professor, Associate professor, Lecturer(0/1/2/3)
	COURSE *offeredCourses;
	int Thoursalloted;	// Theory
	int Lhoursalloted;	// Lab
}FACULTY;

//ANIRUDH
typedef struct CLASSROOM{
	int clid;
	int seats;
	char clname[500];
	int torl;			//Theory or Lab(1/0)
}CLASSROOM;


FACULTY* initFaculty(FACULTY *f,int n){
	char names[5][25]={"Paul Braineard","Rajendra Prasath","Ashwin","Amitava Das","Snehasis Mukherjee"};
	int i,j,temp,size=0,stores[1000]={0};
	bool flag;
	f=(FACULTY*)malloc(n*sizeof(FACULTY));
	for(i=0;i<n;i++){
		do{
			flag=false;
			temp=rand()%n+1000;
			for(j=0;j<size;j++)
				if(stores[j]==temp)
					flag=true;
		}while(flag);
		stores[size++]=temp;
		strcpy(f[i].fname,names[i]);
		f[i].pos=rand()%4;
		f[i].fid=rand()%21+1000;
		f[i].offeredCourses=NULL;
		f[i].Thoursalloted=f[i].Lhoursalloted=0;
	}
	return f;
}
/*
void append(COURSE *head, char s[]){
	
	temp=(COURSE*)malloc(sizeof(COURSE));
	strcpy(temp->name,s);
	if(head==NULL)
		{
			head=temp;
			temp->next=NULL;
		}
	else
		{
			temp->next=head;
			head=temp;	
		}
}
*/

COURSE* initCourse(COURSE *c, int n){		// 'n' should be at least less than the size of this names array. Remember to take that into consideraton:)
	char names[20][50]={"BEC","CO","DS","CS","DM"};
	int temp,i,j,size=0,stores[1000]={0};
	bool f; 
	c=(COURSE*)malloc(n*sizeof(COURSE));
	for(i=0;i<n;i++){
		do{
			f=false;
			temp=rand()%n+100;
			for(j=0;j<size;j++)
				if(stores[j]==temp)
					f=true;
		}while(f);
		c[i].id=stores[size++]=temp;
		strcpy(c[i].name,names[i]);
		if(strcmp(c[i].name,"DS")==0 || strcmp(c[i].name,"BEC")==0){
			c[i].hours+=7;
			c[i].credits=5;
		}
		else{
			c[i].hours+=4;
			c[i].credits=4;
		}
	}
	return c;
}

STUDENT* initStudent(STUDENT *s,int n){
	n=160;
	
	char names[320][60]={"Aakash Shukla","aakash.s16@iiits.in", "ABHILASH P","abhilash.p16@iiits.in", "ABHISHEK THRIPURANA","abhishek.t16@iiits.in", "ADAMYA GUPTA","adamya.g16@iiits.in",
    "ADITYA HARIDAS MENON","adityaharidas.m16@iiits.in", "ANIRUDH KANNAN VP","anirudhkannan.v16@iiits.in", "ANJALI POORNIMA KARRI","anjalipoornima.k16@iiits.in", "ANUBHAV UJJAWAL","anubhav.u16@iiits.in",
    "ANURAG GUPTA","anurag.g16@iiits.in", "ARSHAD G","arshad.g16@iiits.in", "ARVIND DESHRAJ","arvind.d16@iiits.in", "ASHISH KUMAR PATEL","ashishkumar.p16@iiits.in", "ASWANTH NAYAK BHUKYA","aswanthnayak.b16@iiits.in", 
    "BHAVI CHAWLA","bhavi.c16@iiits.in", "CHANDRAJEET CHOUDHARY","chandrajeet.c16@iiits.in", "Chinmay Samal","chinmay.s16@iiits.in", "DEEKSHA UMMADI","deeksha.u16@iiits.in", "DEEPAK KUMAR","deepak.k16@iiits.in", 
    "DEVENDER NAIK BHUKYA","devendernaik.b16@iiits.in", "DHARANI MADDELA","dharani.m16@iiits.in", "DHARANI DEVI AKURATHI","dharanidevi.a16@iiits.in", "DHEERAJ CHAPPIDI","dheeraj.c16@iiits.in", 
    "DHRUV ROSHAN MESHRAM","dhruvroshan.m16@iiits.in", "GARVIT KATARIA","garvit.k16@iiits.in", "HAREESH THIRUKKOVALLURU","hareesh.t16@iiits.in", "HEMANTH KUMAR MADDI","hemanthkumar.m16@iiits.in", 
    "HEMANTH KUMAR YELLURU","hemanthkumar.y16@iiits.in", "HINDUJA BIKKI","hinduja.b16@iiits.in", "JADHAV AJIT JAYWANT","jadhavajit.j16@iiits.in", "JAGADEESH SUMANTH SAGGURTHI","jagadeeshsumanth.s16@iiits.in",
    "JAHNAVI BARINELA","jahnavi.b16@iiits.in", "JAHNAVI GUJJULA","jahnavi.g16@iiits.in", "JASWANTH KUMAR YADAGALLA","jaswanthkumar.y16@iiits.in", "JHANSI RANI CHEEMALADINNE","jhansirani.c16@iiits.in",
    "JUNAID NZ","junaid.nz16@iiits.in", "KAUSTUBH PANDEY","kaustubh.p16@iiits.in", "KEERTHI PRIYANKA LAM","keerthipriyanka.l16@iiits.in", "SRI KRISHNA KARTHIK GAMPALA","krishnakarthik.g16@iiits.in",
    "KRISHNA KUMAR DEY","krishnakumar.d16@iiits.in", "KRISHNA VAMSI DIRISALA","krishnavamsi.d16@iiits.in", "LAISHA WADHWA","laisha.w16@iiits.in", "LAVANYA BANOTH","lavanya.b16@iiits.in", 
    "SAI MADHU CHANDHANA PYAPALI","madhuchandhana.p16@iiits.in", "MADHU SUDHAN PUNGANOOR","madhusudhan.p16@iiits.in", "Mahathi D","mahathi.d16@iiits.in", "MAHESHWARI K","maheshwari.k16@iiits.in",
    "MANOGNA PAGADALA","manogna.p16@iiits.in", "MARY ANKITHA GORREMUCHU","maryankitha.g16@iiits.in", "MEGHANA KANAPANENI","meghana.k16@iiits.in", "MONICA SAGAR G","monicasagar.g16@iiits.in",
    "MOUNIKA CHADALAVADA","mounika.c16@iiits.in", "MRITYUNJAY KUMAR OJHA","mrityunjaykumar.o16@iiits.in", "MRUDULA SHASTRI PULLELA","mrudulashastri.p16@iiits.in", "MUNI NIHITHA CHOWDARY PULIVARTHI","muninihitha.p16@iiits.in",
    "NAGA SIVA KRISHNA CHERUVUGATTU","nagasivakrishna.c16@iiits.in", "NAVANITH RAYAVARAPU","navanith.r16@iiits.in", "NIHARIKA CHALAPAKA","niharika.c16@iiits.in", "NIKHIL KUMAR CHILAGANI","nikhilkumar.c16@iiits.in", 
    "NIKHIL SAI KAGITA","nikhilsai.k16@iiits.in", "NITIN KUMAR","nitin.k16@iiits.in", "PADMINI CHENNAMSETTY","padmini.c16@iiits.in", "PARAS DAHIYA","paras.d16@iiits.in", "PARKHI MOHAN","parkhi.m16@iiits.in", 
    "PAVAN SAI MUCHERLA","pavansai.m16@iiits.in", "PAWAN KALYAN REDDY DAKKATA","pawankalyanreddy.d16@iiits.in", "PRADEEP TURUN","pradeep.t16@iiits.in", "PRAKKASH MANOHAR","prakkash.m16@iiits.in", 
    "PRANAV MEEJURI","pranav.m16@iiits.in", "Prasad Vishal Dinesh","prasadvishal.d16@iiits.in", "PRASHANT KUMAR MAHANTA","prashantkumar.m16@iiits.in", "PRATHYUSH POTLURI","prathyush.p16@iiits.in",
    "PREETHI SAMALA","preethi.s16@iiits.in", "PREETHI HENA DINDIGALLA","preethihena.d16@iiits.in", "PRINCE KUMAR","prince.k16@iiits.in", "SATYA SAI PRUDHVI KRISHNA NIKKU","prudhvikrishna.n16@iiits.in", 
    "PRUDHVI RAJ JWALA","prudhviraj.j16@iiits.in", "RAHUL KUMAR","rahul.k16@iiits.in", "RAHUL RAGHAVA PEELA","rahulraghava.p16@iiits.in", "RAJA RAMA CHANDRA RAO VARRI","rajaramachandrarao.v16@iiits.in",
    "RAM SAI RAHUL MOTIPALLE","ramsairahul.m16@iiits.in", "RAVI TEJA KOMMENDALA","raviteja.k16@iiits.in", "RENUKARAM SAJJA","renukaram.s16@iiits.in", "RISHAV CHANDRA VARMA","rishavchandra.v16@iiits.in",
    "RISHITHA PULLURU","rishitha.p16@iiits.in", "ROHAN S","rohan.s16@iiits.in", "ROHIT CHOWDARY ATLURI","rohitchowdary.a16@iiits.in", "RUSHEEL KOUSHIK GOLLAKOTA","rusheelkoushik.g16@iiits.in", 
    "RUTVIK REDDY VIJJAL","rutvikreddy.v16@iiits.in", "SAGAR R","sagar.r16@iiits.in", "SAHAJ AGARWAL","sahaj.a16@iiits.in", "SAHITHI KRISHNA KOTTE","sahithikrishna.k16@iiits.in", "SAI KARANAM MANASA","saikaranam.m16@iiits.in", 
    "SAI KEERTHI DOMA","saikeerthi.d16@iiits.in", "SAI KIRAN THAMMALI","saikiran.t16@iiits.in", "DASARADHASRI RAM SAI MANI TEJA AKASAPU","saimaniteja.a16@iiits.in", "NAGA VENKATA SAI MANOJ GURRAM","saimanoj.g16@iiits.in",
    "UPENDRA SAINATH REDDY K","sainathreddy.k16@iiits.in", "SAI PRASANNA KUMAR KUMARU","saiprasannakumar.k16@iiits.in", "SAIRATHAN VENTRAPRAGADA","sairathan.v16@iiits.in", "SRIKARA MOHANA SAI SACHIN NEKKANTI","saisachin.n16@iiits.in",
    "SAI SUHAS TANMAY K","saisuhastanmay.k16@iiits.in", "SAI SUPRIYA D","saisupriya.d16@iiits.in", "SAI SURESH GUDURU","saisuresh.g16@iiits.in", "SAI TEJA AVADHOOTHA","saiteja.a16@iiits.in", "DASHARATHA SAI VAMSHI SALLA","saivamshi.s16@iiits.in",
    "SAKIR SHAH","sakir.s16@iiits.in", "SANDEEP POTLA","sandeep.p16@iiits.in", "SANYEM GUPTA","sanyem.g16@iiits.in", "SARIN RAJENDRA NIKOSE","sarinrajendra.n16@iiits.in", "SATYA BALA ANUSHA SATYAVOLU","satyabalaanusha.s16@iiits.in",
    "SATYA SAI VENKATA RAJA YALLA","satyasaivenkataraja.y16@iiits.in", "SHASHWAT SHUKLA","shashwat.s16@iiits.in", "SHIVAM SINGH YADAV","shivamsingh.y16@iiits.in", "SHIVANI CHEPURI","shivani.c16@iiits.in", "SHOBHIT MALARYA","shobhit.m16@iiits.in",
    "SHRUTHI MS","shruthi.ms16@iiits.in", "SHUBHAM GUPTA","shubham.g16@iiits.in", "SIDDHANT KUSHWAHA","siddhant.k16@iiits.in", "SIDDHARTH KUMAR","siddharth.k16@iiits.in", "SOUMIK MANDAL","soumik.m16@iiits.in", "SOWMYA MAHESHWARAM","sowmya.m16@iiits.in", 
    "SOWMYA VASUKI JALLEPALLI","sowmyavasuki.j16@iiits.in", "SREE HARSHITHA POLAMADA","sreeharshitha.p16@iiits.in", "SREE PRAGNA VINNAKOTI","sreepragna.v16@iiits.in", "SRI GIRINADH TANNERU","srigirinadh.t16@iiits.in",
    "SRI HARSHA VARRI","sriharsha.v16@iiits.in", "SRI HARSHAVARDHAN S","sriharshavardhan.s16@iiits.in", "SRI HARSHITHA KASTURI","sriharshitha.k16@iiits.in", "SRIJAN REDDY VASA","srijanreddy.v16@iiits.in", "SRILEKHA NARANAPURAM","srilekha.n16@iiits.in",
    "SAI KRISHNA SUBASH KARTHIKEYA MANTHRI","subashkarthikeya.m16@iiits.in","SRINIVAS RAO MARADANA","srinivasrao.m16@iiits.in", "SUBHADEEP DASH","subhadeep.d16@iiits.in", "SUDHEERA SIVANI BILLAKURTI","sudheerasivani.b16@iiits.in", "SUMAN VANKUDOTHU","suman.v16@iiits.in",
    "SUMANTH DODDAPANENI","sumanth.d16@iiits.in", "SUMANTH KONASAMUDRAM","sumanth.k16@iiits.in", "SUNIL JS","sunil.js16@iiits.in", "SURYA TEJA ACHANTA","suryateja.a16@iiits.in", "SUSHANTH POJJARI","sushanth.p16@iiits.in",
    "SYED JAHANGIR PEERAN","syedjahangir.p16@iiits.in", "TANMAY KALANI","tanmay.k16@iiits.in", "TEJKIRAN V","tejkiran.v16@iiits.in", "TRIPATHI ITI","tripathi.i16@iiits.in", "UDYA RAJ SAWHNEY","udyaraj.s16@iiits.in", "VAMSI KRISHNA MADAKA","vamsikrishna.m16@iiits.in",
    "VASANTH NIKHIL SINGH","vasanthnikhil.s16@iiits.in", "VEDA BARRENKALA","veda.b16@iiits.in", "VEENA PRATHYUSHA BOLLAPRAGADA","veenaprathyusha.b16@iiits.in", "VENKATA CHARAN GOWTHUKATLA","venkatacharan.g16@iiits.in", 
    "VENKATA SAI KRISHNA DESHINENI","venkatasaikrishna.d16@iiits.in", "VENKATA VAISHNAVI NALLURI","venkatavaishnavi.n16@iiits.in", "VENKATESH SAKI","venkatesh.s16@iiits.in", "VENKAT LOKESH KUMAR SAJJANAPU","venkatlokeshkumar.s16@iiits.in", 
    "VINOOTHNA SAI KINNERA","vinoothnasai.k16@iiits.in", "VISHAKHA SHASHIKANT KHURANGALE","vishakhashashikant.k16@iiits.in", "VISHNU VARDHAN KILLU","vishnuvardhan.k16@iiits.in", "SAI NAGA VISWA CHAITANYA BASAVA","viswachaitanya.b16@iiits.in",
    "WASIM ISHAQ KHAN","wasim.i16@iiits.in", "YASHWANTH VENKATA SUBBA REDDY PAPPULA","yashwanth.p16@iiits.in"};
    int i,j=0,temp,size=0,noOfCourses,index;
	bool flag;
	s=(STUDENT*)malloc(3*sizeof(STUDENT));
	s[j].sd=(STUDENTDETAILS*)malloc(81*sizeof(STUDENTDETAILS));
	for(i=0;i<81;i++){
		if(i==80 && j==0){
			strcpy(s[j].sd[i].name,"NULL");
			j++;
			i=0;
			s[j].sd=(STUDENTDETAILS*)malloc(81*sizeof(STUDENTDETAILS));		
		}
		else if (i==80 && j==1){
			break;
		}	
		strcpy(s[j].sd[i].name,names[2*(i+(j*80))]);
		s[j].sd[i].id=i+(j*80)+201601001;
		s[j].sd[i].year=2016;
		if(i<80)
			s[j].sd[i].batch='A';
		else
			s[j].sd[i].batch='B';
		strcpy(s[j].sd[i].email,names[2*(i+(j*80))+1]);
		s[j].sd[i].credits=20+rand()%18;
		s[j].sd[i].takenCourses=NULL;
		s[j].sd[i].takenCourses=initCourse(s[j].sd[i].takenCourses,5);;
	}
	strcpy(s[j].sd[i].name,"NULL");
	j++;
	s[j].sd=(STUDENTDETAILS*)malloc(161*sizeof(STUDENTDETAILS));
	for(i=0;i<160;i++){
			
		strcpy(s[j].sd[i].name,names[2*i]);
		s[j].sd[i].id=i+201601001;
		s[j].sd[i].year=2016;
		if(i<80)
			s[j].sd[i].batch='A';
		else
			s[j].sd[i].batch='B';
		strcpy(s[j].sd[i].email,names[2*i+1]);
		s[j].sd[i].credits=20+rand()%18;
		s[j].sd[i].takenCourses=NULL;
		s[j].sd[i].takenCourses=initCourse(s[j].sd[i].takenCourses,5);;
	}
	strcpy(s[j].sd[i].name,"NULL");
	return s;
}

//ANIRUDH
CLASSROOM* initClassrooms(CLASSROOM *cl,int n){
	char names[5][25]={"Computer Lab","Classroom-305","Electronics Lab","Classroom-314","Lecture Room"};
	int i,j,temp,size=0,stores[1000]={0};
	bool f;
	cl=(CLASSROOM*)malloc(n*sizeof(CLASSROOM));
	for(i=0;i<n;i++){
		do{
			f=false;
			temp=rand()%n+300;
			for(j=0;j<size;j++)
				if(stores[j]==temp)
					f=true;
		}while(f);
		cl[i].clid=stores[size++]=temp;
		strcpy(cl[i].clname,names[i]);
		if(strcmp(cl[i].clname,"Project Lab")==0 || strcmp(cl[i].clname,"Computer Lab")==0 || strcmp(cl[i].clname,"Electronics Lab")==0){
			cl[i].torl=0;
			cl[i].seats=80;
		}
		else if(strcmp(cl[i].clname,"Classroom-305")==0 || strcmp(cl[i].clname,"Lecture Room")==0){
			cl[i].torl=2;
			cl[i].seats=80;
		}
		else{
			cl[i].torl=1;
			cl[i].seats=160;	
		}
	}
	return cl;
}
typedef struct ALL{
	CLASSROOM *cl;
	FACULTY *f;
	STUDENT *s;
	STUDENTDETAILS *sd;
	COURSE *c;
}ALL;
//ANIRUDH
typedef struct ALLQUEUE{
	ALL *all;
	struct ALLQUEUE *next;
}ALLQUEUE;

//ANIRUDH
ALLQUEUE *insertQueue(ALLQUEUE *queue, ALL *temp){
	ALLQUEUE *front=queue,*rear;
	rear=(ALLQUEUE *)malloc(sizeof(ALLQUEUE));
	rear->all=temp;
	rear->next=NULL;
	if(queue==NULL) 
		return rear;
	while(queue->next!=NULL)
		queue=queue->next;
	queue->next=rear;
	return front;
}

void printqueue(ALLQUEUE *queue){
	if(queue==NULL)
		return;
	int i=0;
	// Classroom details
	printf("CLassroom ID : %d\nNo. of seats : %d\nClass Room Name : %s\nTheory or lab? : %d\nCourse: %s\n\n",queue->all->cl->clid,queue->all->cl->seats,queue->all->cl->clname,queue->all->cl->torl,queue->all->c->name);
	printf("----------------------------------------------------------------------------\n");
	// Faculty details
	while(strcmp(queue->all->sd[i].name,"NULL")!=0){
		printf("%s-",queue->all->sd[i].name);
		i++;
	}
	printf("\n");
	printf("Faculty ID : %d\nPosition : %d\nFaculty Name : %s\n\n",queue->all->f->fid,queue->all->f->pos,queue->all->f->fname);
	printf("----------------------------------------------------------------------------\n");
	printf("----------------------------------------------------------------------------\n");
	printqueue(queue->next);
	return;
}


ALLQUEUE* functionToQueueUp(ALL *all){
	
	ALLQUEUE *allqueue=NULL;
	ALL *temp=(ALL*)malloc(sizeof(ALL));
//---------------------------------------------------
	temp->cl=&(all->cl[0]);
	temp->f=&(all->f[1]);
	temp->sd=all->s[0].sd;
	temp->c=&(all->c[2]);									// DS LAB BATCH-A ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------
    temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[0]);
	temp->f=&(all->f[1]);
	temp->sd=all->s[1].sd;
	temp->c=&(all->c[2]);									// DS LAB BATCH-B ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------

	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[2]);
	temp->f=&(all->f[0]);
	temp->sd=all->s[0].sd;
	temp->c=&(all->c[0]);									// BEC LAB BATCH-A ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.	
//---------------------------------------------------
	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[2]);
	temp->f=&(all->f[0]);
	temp->sd=all->s[1].sd;
	temp->c=&(all->c[0]);									// BEC LAB BATCH-B ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.	
//---------------------------------------------------
	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[3]);
	temp->f=&(all->f[1]);
	temp->sd=all->s[2].sd;
	temp->c=&(all->c[2]);									// DS Class ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------
	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[3]);
	temp->f=&(all->f[0]);
	temp->sd=all->s[2].sd;
	temp->c=&(all->c[0]);									// BEC Class ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------

	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[3]);
	temp->f=&(all->f[3]);
	temp->sd=all->s[2].sd;
	temp->c=&(all->c[1]);									// CO Class ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------
	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[3]);
	temp->f=&(all->f[4]);
	temp->sd=all->s[2].sd;
	temp->c=&(all->c[4]);									// DM Class ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------
	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[3]);
	temp->f=&(all->f[2]);
	temp->sd=all->s[2].sd;
	temp->c=&(all->c[3]);									// Comm-Skills Class ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------
	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[1]);
	temp->f=&(all->f[0]);
	temp->sd=all->s[0].sd;
	temp->c=&(all->c[0]);									// BEC Tute Batch-A ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------
	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[4]);
	temp->f=&(all->f[0]);
	temp->sd=all->s[1].sd;
	temp->c=&(all->c[0]);									// BEC Tute Batch-B ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------

	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[1]);
	temp->f=&(all->f[1]);
	temp->sd=all->s[0].sd;
	temp->c=&(all->c[2]);									// DS Tute Batch-A ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------
	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[4]);
	temp->f=&(all->f[1]);
	temp->sd=all->s[1].sd;
	temp->c=&(all->c[2]);									// DS Tute Batch-B ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------

	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[4]);
	temp->f=&(all->f[3]);
	temp->sd=all->s[0].sd;
	temp->c=&(all->c[1]);									// CO Tute Batch-A ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------

	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[1]);
	temp->f=&(all->f[3]);
	temp->sd=all->s[1].sd;
	temp->c=&(all->c[1]);									// CO Tute Batch-B ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------

	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[4]);
	temp->f=&(all->f[4]);
	temp->sd=all->s[0].sd;
	temp->c=&(all->c[4]);									// Mathematics Tute Batch-A ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------

	temp=(ALL*)malloc(sizeof(ALL));
	temp->cl=&(all->cl[1]);
	temp->f=&(all->f[4]);
	temp->sd=all->s[1].sd;
	temp->c=&(all->c[4]);									// Mathematics Tute Batch-B ADDED TO QUEUE.
	temp->s=all->s;
	// Node created.
	allqueue=insertQueue(allqueue,temp);
	// Inserted that node.
//---------------------------------------------------

	//printqueue(allqueue);
}
//ANIRUDH
ALLQUEUE *dequeue(ALLQUEUE *queue){
	if(queue==NULL) 
		return NULL;
	ALLQUEUE *temporary=queue;
	queue=queue->next;
	free(temporary);
	return queue;
}

//ANIRUDH
/*ALLQUEUE* createClassQueue(ALLQUEUE *q,CLASSROOM *cl, int n){
	int i;
	ALLQUEUE *allqueue=NULL;
	for(i=0;i<n;i++)
		if(cl[i].torl==0)
			q=insertQueue(allqueue,&cl[i]);
	for(i=0;i<n;i++)
		if(cl[i].torl)
			q=insertQueue(allqueue,&cl[i]);
}*/
bool checkAllotedSlot(ALL ***timetable,int i,int j,int k){
 /*To check whether a particular array location is already alloted or yet to be alloted.*/
	if(timetable[i][j][k].cl==NULL && timetable[i][j][k].f==NULL && timetable[i][j][k].s==NULL && timetable[i][j][k].c==NULL && timetable[i][j][k].sd==NULL)
		return true;
	return false;
}
void initialiseFreshTimeTable(ALL ***timetable){	
/* To initialise all the slots in all the timetables[][][] to NULL .*/
	int i,j,k;
	for(i=0;i<12;i++)
		for(j=0;j<6;j++)
			for(k=0;k<8;k++){
				timetable[i][j][k].cl=NULL;
				timetable[i][j][k].f=NULL;
				timetable[i][j][k].s=NULL;
				timetable[i][j][k].c=NULL;
				timetable[i][j][k].sd=NULL;
			}
}
int findFacultyIndex(ALL *all,char s[]){
	int i=0;
	while(strcmp(all->f[i].fname,s)!=0){
		i++;
	}
	return i;
}
int findClassroomIndex(ALL *all,char s[]){
	int i=0;
	while(strcmp(all->cl[i].clname,s)!=0){
		i++;
	}
	return i;
}
void generateTimeTable(ALL ***timetable,ALLQUEUE *allqueue, ALL *all){
	int x,y,j=1,i,z,ind,flag=0;
	/* Create a fresh Layout of the timetable*/
	initialiseFreshTimeTable(timetable);
	/*First DS and BEC labs*/
		/*We will insert DS and BEC labs on tuesdays and thursdays.(Randomly for Batch A and Batch B)*/
		if(rand()%2){
			j=3;
		}
		// DS LAB inserted for both batches in both random ways.
			/*Inserting in Batch A students' timetables:*/
				//timetable[Batch-A][Tuesday/Thursday][time: 2-5] = DS LAB
				timetable[0][j][4]=timetable[0][j][5]=timetable[0][j][6]=*(allqueue->all);
			/*Inserting in faculty's timetable:*/
				//timetable[Teacher][Tuesday/Thursday][time: 2-5] = DS LAB
				x=findFacultyIndex(all,allqueue->all->f->fname);
				timetable[x+2][j][4]=timetable[x+2][j][5]=timetable[x+2][j][6]=*(allqueue->all);
			/*Inserting in classroom's timetable:*/
				//timetable[classroom][Tuesday/Thursday][time: 2-5] = DS LAB 
				x=findClassroomIndex(all,allqueue->all->cl->clname);
				timetable[x+7][j][4]=timetable[x+7][j][5]=timetable[x+7][j][6]=*(allqueue->all);
			/* Now Dequeue that element*/
			allqueue=dequeue(allqueue);                                                                                                                                    
			/*Inserting in students' timetables:*/
				//timetable[Batch-B][Tuesday/Thursday][time: 2-5] = DS LAB 
				timetable[1][4-j][4]=timetable[1][4-j][5]=timetable[1][4-j][6]=*(allqueue->all);
			/*Inserting in faculty's timetable:*/
				//timetable[Teacher][Tuesday/Thursday][time: 2-5] = DS LAB 
				x=findFacultyIndex(all,allqueue->all->f->fname);
				timetable[x+2][4-j][4]=timetable[x+2][4-j][5]=timetable[x+2][4-j][6]=*(allqueue->all);
			/*Inserting in classroom's timetable:*/
				//timetable[classroom][Tuesday/Thursday][time: 2-5] = DS LAB 
				x=findClassroomIndex(all,allqueue->all->cl->clname);
				timetable[x+7][4-j][4]=timetable[x+7][4-j][5]=timetable[x+7][4-j][6]=*(allqueue->all);
			/* Now Dequeue that element*/
			allqueue=dequeue(allqueue);
		// BEC LAB inserted for both batches in both random ways.
			/*Inserting in Batch A students' timetables:*/
				//timetable[Batch-A][Tuesday/Thursday][time: 2-5] = DS LAB 
				timetable[0][4-j][4]=timetable[0][4-j][5]=timetable[0][4-j][6]=*(allqueue->all);
			/*Inserting in faculty's timetable:*/
				//timetable[Teacher][Tuesday/Thursday][time: 2-5] = DS LAB
				x=findFacultyIndex(all,allqueue->all->f->fname);
				timetable[x+2][4-j][4]=timetable[x+2][4-j][5]=timetable[x+2][4-j][6]=*(allqueue->all);
			/*Inserting in classroom's timetable:*/
				//timetable[classroom][Tuesday/Thursday][time: 2-5] = DS LAB 
				x=findClassroomIndex(all,allqueue->all->cl->clname);
				timetable[x+7][4-j][4]=timetable[x+7][4-j][5]=timetable[x+7][4-j][6]=*(allqueue->all);
			/* Now Dequeue that element*/
			allqueue=dequeue(allqueue);
			/*Inserting in students' timetables:*/
				//timetable[Batch-B][Tuesday/Thursday][time: 2-5] = DS LAB 
				timetable[1][j][4]=timetable[1][j][5]=timetable[1][j][6]=*(allqueue->all);
			/*Inserting in faculty's timetable:*/
				//timetable[Teacher][Tuesday/Thursday][time: 2-5] = DS LAB 
				x=findFacultyIndex(all,allqueue->all->f->fname);
				timetable[x+2][j][4]=timetable[x+2][j][5]=timetable[x+2][j][6]=*(allqueue->all);
			/*Inserting in classroom's timetable:*/
				//timetable[classroom][Tuesday/Thursday][time: 2-5] = DS LAB 
				x=findClassroomIndex(all,allqueue->all->cl->clname);
				timetable[x+7][j][4]=timetable[x+7][j][5]=timetable[x+7][j][6]=*(allqueue->all);
			/* Now Dequeue that element*/
			allqueue=dequeue(allqueue);
	/*All lecture classes*/
			int blockind1=-1;
			int blockind2=-1;
			for(i=0;i<5;i++){
				for(z=0;z<3;z++){
					do{
						x=rand()%6;
						y=rand()%4;
					}while(timetable[0][x][y].c!=NULL || y==blockind1 || y==blockind2);
					blockind1=y-1;
					blockind2=y+1;
					//No Continuous classes add that conditon-----------------------------------------------------------------------------------------------------------------------:)
					timetable[0][x][y]=timetable[1][x][y]=*(allqueue->all);
					ind=findFacultyIndex(all,allqueue->all->f->fname);
					timetable[ind+2][x][y]=*(allqueue->all);
					ind=findClassroomIndex(all,allqueue->all->cl->clname);
					timetable[ind+7][x][y]=*(allqueue->all);
				}
				allqueue=dequeue(allqueue);
			}
	/*All Tutorial classes*/
			for(i=1;i<=2;i++){
				do{
					x=rand()%6;
					y=4+rand()%3;
				}while(timetable[(i+1)%2][x][y].c!=NULL || timetable[(i+1)%2][x][y+1].c!=NULL);

				timetable[(i+1)%2][x][y]=*(allqueue->all);
				ind=findFacultyIndex(all,allqueue->all->f->fname);
					timetable[ind+2][x][y]=*(allqueue->all);
					ind=findClassroomIndex(all,allqueue->all->cl->clname);
					timetable[ind+7][x][y]=*(allqueue->all);
				allqueue=dequeue(allqueue);


				timetable[i%2][x][y+1]=*(allqueue->all);
				ind=findFacultyIndex(all,allqueue->all->f->fname);
					timetable[ind+2][x][y+1]=*(allqueue->all);
					ind=findClassroomIndex(all,allqueue->all->cl->clname);
					timetable[ind+7][x][y+1]=*(allqueue->all);	
				allqueue=dequeue(allqueue);

				timetable[(i+1)%2][x][y+1]=*(allqueue->all);
				ind=findFacultyIndex(all,allqueue->all->f->fname);
					timetable[ind+2][x][y+1]=*(allqueue->all);
					ind=findClassroomIndex(all,allqueue->all->cl->clname);
					timetable[ind+7][x][y+1]=*(allqueue->all);	
				allqueue=dequeue(allqueue);


				timetable[i%2][x][y]=*(allqueue->all);
				ind=findFacultyIndex(all,allqueue->all->f->fname);
					timetable[ind+2][x][y]=*(allqueue->all);
					ind=findClassroomIndex(all,allqueue->all->cl->clname);
					timetable[ind+7][x][y]=*(allqueue->all);
				allqueue=dequeue(allqueue);

				}


}
void printShortTimeTableForStudents(ALL ***timetable, int i){
	int j,k;
	char days[6][5]={"Mon|","Tue|","Wed|","Thu|","Fri|","Sat|"};
	printf("\t");
	for(k=9;k<12;k++)
		printf("%d-%d\t",k,k+1);
	for(k=1;k<=5;k++)
		printf("%d-%d\t",k,k+1);
	printf("\n");
	for(j=0;j<6;j++){
		printf("%s\t",days[j]);
		for(k=0;k<8;k++)
			if(timetable[i][j][k].c==NULL)
				printf("---\t");
			else{ 
					printf("%s",timetable[i][j][k].c->name);
					if(timetable[i][j][k].cl->torl==1)
						printf("(C)\t");
					else if(timetable[i][j][k].cl->torl==2)
						printf("(T)\t");
					else
						printf("(L)\t");
			}
		printf("\n");
	}
}
void printShortTimeTableForFaculties(ALL ***timetable, int i){
	int j,k;
	char days[6][5]={"Mon|","Tue|","Wed|","Thu|","Fri|","Sat|"};
	printf("\t");
	for(k=9;k<12;k++)
		printf("%d-%d\t",k,k+1);
	for(k=1;k<=5;k++)
		printf("%d-%d\t",k,k+1);
	printf("\n");
	for(j=0;j<6;j++){
		printf("%s\t",days[j]);
		for(k=0;k<8;k++)
			if(timetable[i][j][k].cl==NULL)
				printf("---\t");
			else{
				printf("%d",timetable[i][j][k].cl->clid);
				if(timetable[i][j][k].cl->torl==1)
						printf("(C)\t");
					else if(timetable[i][j][k].cl->torl==2)
						printf("(T)\t");
					else
						printf("(L)\t");
			}
		printf("\n");
	}
}
void printShortTimeTableForClassrooms(ALL ***timetable, int i){
	int j,k;
	char days[6][5]={"Mon|","Tue|","Wed|","Thu|","Fri|","Sat|"};
	printf("\t");
	for(k=9;k<12;k++)
		printf("%d-%d\t",k,k+1);
	for(k=1;k<=5;k++)
		printf("%d-%d\t",k,k+1);
	printf("\n");
	for(j=0;j<6;j++){
		printf("%s\t",days[j]);
		for(k=0;k<8;k++)
			if(timetable[i][j][k].c==NULL)
				printf("---\t");
			else
				printf("%s\t",timetable[i][j][k].c->name);
		printf("\n");
	}
}
void printTimeTable(ALL ***timetable, int i){

}
void requestAndPrint(ALL ***timetable){
	printf("The set of TimeTables have been generated..\n\n");
	int ch0,ch1;
	char choice='y';
	do{
		printf("Enter your request as per the following prototype:\n\n");
		restart:
		printf("Press 0: For Students' Timetable\nPress 1: For Faculty's Timetable\nPress 2: For Classroom's Timetable\n");
		scanf(" %d",&ch0);
		switch(ch0){
			case 0:
					askagain:
					printf("Press 0: For Batch A Students' Timetable\nPress 1: For Batch B Students' Timetable\n");
					scanf(" %d",&ch1);
					if(ch1!=0 && ch1!=1)
						goto askagain;
					printShortTimeTableForStudents(timetable,ch1);
					printTimeTable(timetable,ch1);
					break;
			case 1:	
					askagain2:
					printf("Press 0: For Dr. Rajendra Prasath's Timetable\nPress 1: For Dr. Paul Braineard's Timetable\nPress 2: For Mr. Ashwin's Timetable\nPress 3: For Dr. Amitava Das' Timetable\nPress 4: For Dr. Snehasis Mukherjee's Timetable\n");
					scanf(" %d",&ch1);
					if(ch1<0 || ch1>4)
						goto askagain2;
					if(ch1<2)
						ch1=1-ch1;
					printShortTimeTableForFaculties(timetable,ch1+2);
					printTimeTable(timetable,ch1+2);
					break;
			case 2:	
					printf("Press 0: For the Timetable of Computer Lab\nPress 1: For the Timetable of Classroom-305\nPress 2: For the Timetable of Electronics Lab\nPress 3: For the Timetable of Classroom-314\nPress 4: For the Timetable of Lecture Room\n");
					scanf(" %d",&ch1);
					printShortTimeTableForClassrooms(timetable,ch1+7);
					printTimeTable(timetable,ch1+7);
					break;
			default:goto restart;
		}
		requestAgain:
		printf("Do you have any other requests?(y or n) : ");
		scanf(" %c",&choice);
		if(choice!='y' && choice!='n')
			goto requestAgain;
	}while(choice=='y');
}
void printFaculties(FACULTY *f, int n){
	int i;
	for(i=0;i<n;i++)
		printf("Faculty ID : %d\nPosition : %d\nFaculty Name : %s\n\n",f[i].fid,f[i].pos,f[i].fname);
	printf("----------------------------------------------------------------------------\n");
}
void printStudent(STUDENT *s, int n){
	int i,j,k=0;
	n=160;
	for(i=0;i<81;i++){
		if(i==80 && k==0){
			k++;
			i=0;
		}
		else if (i==80 && k==1){
			break;
		}
		printf("Student ID : %d\nStudent Name : %s\nYear of Join : %d\nBatch : %c\nEmailID : %s\nCredits : %d\n",s[k].sd[i].id,s[k].sd[i].name,s[k].sd[i].year,s[k].sd[i].batch,s[k].sd[i].email,s[k].sd[i].credits);
		printf("List of courses opted:\n%s",s[k].sd[i].takenCourses[0].name);
		for(j=1;j<5;j++)
		printf("-%s",s[k].sd[i].takenCourses[j].name);
		printf("\n\n");
	}
	printf("----------------------------------------------------------------------------\n");
}
//ANIRUDH
void printClassrooms(CLASSROOM *cl, int n){
	int i;
	for(i=0;i<n;i++)
		printf("CLassroom ID : %d\nNo. of seats : %d\nClass Room Name : %s\nTheory or lab? : %d\n\n",cl[i].clid,cl[i].seats,cl[i].clname,cl[i].torl);
	printf("----------------------------------------------------------------------------\n");
}
void printCourses(COURSE *c, int n){
	int i;
	for(i=0;i<n;i++)
		printf("Course ID : %d\nCourse Name : %s\nCredits : %d\nHours to be given : %d\n\n",c[i].id,c[i].name,c[i].credits,c[i].hours);
	printf("----------------------------------------------------------------------------\n");
}
int main(){
	srand((unsigned int)time(NULL));
	int i,j,k,n1=5,n2=10,n3=5,n4=5;
	COURSE *c=NULL;
	STUDENT *s=NULL;
	FACULTY *f=NULL;
	CLASSROOM *cl=NULL;

	ALL *all=NULL;
	all=(ALL*)malloc(sizeof(ALL));
	//printf("Enter the no. of professors : ");
	//scanf("%d",&n1);
	f=initFaculty(f,n1);
	//printFaculties(f,n1);
	all->f=f;
	/*printf("Enter the no. of student groups : ");
	scanf("%d",&n2);*/
	s=initStudent(s,n2);
	//printStudent(s,n2);
	all->s=s;
	//printf("Enter the no. of classrooms : ");
	//scanf("%d",&n3);
	cl=initClassrooms(cl,n3);
	//printClassrooms(cl,n3);
	all->cl=cl;
	/*printf("Enter the no. of courses : ");
	scanf("%d",&n4);*/
	c=initCourse(c,n4);
	//printCourses(c,n4);
	all->c=c;

	ALLQUEUE *allqueue=NULL;
	allqueue=functionToQueueUp(all);		// NOTE: *allqueue contains 

	ALL ***timetable=NULL;
	timetable=(ALL***)malloc(12*sizeof(ALL**));	
	for(i=0;i<12;i++){
		timetable[i]=(ALL**)malloc(6*sizeof(ALL*));	
		for(j=0;j<6;j++)
			timetable[i][j]=(ALL*)malloc(8*sizeof(ALL));	
	}

	generateTimeTable(timetable,allqueue,all);
	requestAndPrint(timetable);
	return 0;
}
# Timetable-Generator
# OVERVIEW OF THE PROJECT:-

For our project, we chose Queues as the main data structure of our project, as it uses FIFO (FIRST IN FIRST OUT) . The main advantages is that adding or removing elements can be done quickly and efficiently because you would just add elements to the end of the queue or remove them from the front of the queue. The 
Queue made is actually a Priority Queue prioritised in the order of Lab,classroom and then tutorials .

# The MAIN function :-
   The main function automatically creates the Records for faculty,classroom,students and courses each time on startup which inserts the data in a complex data structure (consisting of multidimensional structures) from the records . 
Then the —functiontoQueueup()— function is called which puts all the data in a queue.
Then the —generateTimeTable()— function is called which deques the data and puts in a 3D array.
Then the —requestAndPrint()—   function is called which prints the timetable as requested.
 
 Functions										Description 
 
 1-  FACULTY   *initFaculty(FACULTY *f,int n)           	 		To generate Faculty details
 
 2-  COURSE    *initCourse(COURSE *c,int n)					To generate course details
 
 3-  STUDENT   *initStudent(STUDENT *s,int n)					To generate student details
 
 4-  CLASSROOM *initClassrooms(CLASSROOM *CL,int N)				To generate classroom details
 
 5-  ALLQUEUE *insertqueue(ALLQUEUE *queue,ALL *temp)			To insert an element passed into queue and create a queue
 
 6-  void	printqueue(ALLQUEUE *queue)			To print the details of elements of the queue for verification purposes
 
 7-  ALLQUEUE  *functionToQueueUp(ALL *all)       					To insert elements into the queue in prioritised order
 
 8-  ALLQUEUE  *dequeue(ALLQUEUE *queue)       					To delete the front element in the queue
 
 9-  void       initialiseFreshTimeTable(ALL timetable[][6][8])    			To create a NULL element for each slot of all timetables
 
 10- bool  	  checkAllotedSlot(ALL timetable[][6][8],int i,int j,int k)       	To check whether that slot has been allowed or not
 
 11- void       generateTimeTable(ALL timetable[][6][8],ALLQUEUE *allqueue)       	To generate the timetable
 
 12- void       requestAndPrint(ALL timetable[][6][8])       			To print the requested timetable
 
 13- void       printFaculties(FACULTY *f,int n)   					To print the faculty details for verification purposes
  
 14- void       printStudent(STUDENT *s,int n)   					To print the student details for verification purposes
  
 15- void       printClassrooms(CLASSROOM *cl,int n)   				To print the classroom details for verification purposes
 
 16- void       printCourses(COURSE *c,int n)   					To print the course details for verification purposes

***********************************************************************************************************************************************************************************
                                              Detailed Description
  Functions:
 1) FACULTY   *initFaculty(FACULTY *f,int n)
	         It is a function which will randomly generate faculty details.It will allot position randomly to the professor(Professor,Assistant professor,Associate professor,TA) . This function also allots the professors id , courses offered by him , and the no of theory hours allowed and Lab hours allowed to default values. 
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 2) COURSE    *initCourse(COURSE *c,int n)
		It is a function which will randomly generate course details.It will also allot course details (Subjects like BEC,CO,DS,CS,DM) , no of hours allowed for that 			subject , the no of credits etc.
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 3) STUDENT   *initStudent(STUDENT *s,int n)
		It is a function which will randomly allot student details whether they are in BATCH-A or in BATCH-B.It will also allot their emails , names , the courses taken by 		them and the batch they are in.
		
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 4) CLASSROOM *initClassrooms(CLASSROOM *CL,int N)
		It is a function which will randomly allot classroom details like whether it is a Computer lab, Classroom 305 , Electronics Lab ,Class room 314. 
		It also has a bool variable torl which will tell whether the classroom is whether a theory classroom or lab . It also gives details about the no of seats in the 		classroom .

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 5) ALLQUEUE  *insertqueue(ALLQUEUE *queue,ALL *temp)
		
		It receives a node of type ALL and inserts it in an ALLQUEUE (which is basically a priority queue which follows FIFO in which nodes are inserted at front).
		The nodes are inserted in front in a prioritised manner and a queue is formed . 
		

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 6)  void      printqueue(ALLQUEUE *queue)
		
		It receives a node of type ALLQUEUE which is a priority queue formed by the function insertqueue. It prints all the details of the priority queue in the order 		classroom details, like classroomid, number of seats, classroom name, etc. It next prints faculty details like facultyId, position and faculty name.    

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 7)  ALLQUEUE  *functionToQueueUp(ALL *all)
		This is one of the most important function in this project. It sends the nodes to the priority queue in the order-> Labs->Classes(Lectures)->Tutorials.
		The details of the individual objects of different structures are appended individually. Firstly, both labs of Batch A and B have been enqueued to the priority 		queue. Secondly, we have enqueued the theory classes(lectures) for five different subjects. At last we have enqueued the tutorials for all the subjects except for 		Communications skills.


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 8)  ALLQUEUE  *dequeue(ALLQUEUE *queue)

		This function dequeues the front element of the passed priority queue(allqueue) and returns the new head pointer.
		Before returning, it frees the memory of the dequeued element.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 9)  void       initialiseFreshTimeTable(ALL timetable[][6][8])
		
		It sets all the slots of the timetable(all nodes) to default initial values(NULL).

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 10)  bool  	  checkAllotedSlot(ALL timetable[][6][8],int i,int j,int k)

		This function is essential before allotting theory classes as it checks for a particular period and makes sure that no two theory classes of the same subject are 		allotted in the same slot. It returns true if the slot is free and returns false otherwise.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 11)  void       generateTimeTable(ALL timetable[][6][8],ALLQUEUE *allqueue)
	
		This is one of the most significant function in this project. It basically creates a timetable which has arguments - 3 dimensional structure of timetable with the 		first dimension as the timetable for students, faculty as well as for the classrooms. The second dimension is the days of the week form monday to saturday. The 		third dimension is the periods of the classes of a day. The second argument is an instance of the priority queue which had been formed by the functionToQueueUp.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 12)  void       requestAndPrint(ALL timetable[][6][8])

		This is an interactive function which prompts the user with various options to choose from. And then after an option is chosen, internally, it will prompt its 		respective sub-options to whether print the different students timetable (different BATCHES timetable) or print the different faculties timetable or to print the 		timetable of different faculties depending upon the option entered by the user .     

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 13)  void	printFaculties(FACULTY *f,int n) 
			
		This is a function which prints different faculty details . This function takes a FACULTY object as an argument and prints all the faculty details like 			facultyId, faculty position and faculty name. 

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 14)  void       printStudent(STUDENT *s,int n) 
		
		This function prints the details of different students like studentId, student name, year of join, Batch, emailId, credits. It also prints the list of courses opted 		by them.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 15)  void       printClassrooms(CLASSROOM *cl,int n) 

		This function prints the details of the classrooms like classroomId, number of seats, classroom name, etc. An object of classroom is passed to the function and the 		details of the object are printed- if the bool is true, it is a theory class and if it is false, it is a lab class(torl).
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

 16)  void       printCourses(COURSE *c,int n)

		This function takes an argument of structure course and prints the details of the course like courseId, course name, credits and the number of hours to be given for 		that particular course.

 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void menu(int cfd)
{
    int choice;
    struct message msg;
    char login_id[11];
    char password[11];
    // Creating a Main
    // menu for the user
    begin1:
    wmsg(cfd, 1, 0, "\n\nWelcome to the Course Registration Portal (Academia) \n\nLogin type  \nEnter Your Choice{1. Faculty\n2. Student\n3. Admin\n4. Exit\n\nENTER YOUR CHOICE : ");
    rmsg(cfd,&msg); 
    choice = atoi(msg.body);
        
    wmsg(cfd, 1, 1, "\nEnter Login ID: ");
    rmsg(cfd,&msg);
    strncpy(login_id, msg.body, 10);
    login_id[10]='\0';

    wmsg(cfd, 1, 2, "\nEnter Password: ");
    rmsg(cfd,&msg);
    strncpy(password, msg.body, 10);
    password[10]='\0';

    switch (choice) {
    case 1:
	login_faculty(cfd, login_id, password);
        goto begin1;
    	break;

    case 2:
        login_student(cfd,  login_id, password);
        goto begin1;
        break;

    case 3:
        login_admin(cfd,  login_id, password);
    	goto begin1;
        break;

    case 4:
    	wmsg(cfd, 0, 0, "");
    	exit(1);
    	break;
    default:
    	wmsg(cfd, 0, 1, "Please enter correct choice ...\n");
       	goto begin1;
    }
}


void student_menu(int cfd, int student_id)
{
    int choice;
    struct message msg;
    // Creating a Main
    // menu for the user
    begin2 :
    wmsg(cfd, 1, 0, "\n\n.......WELCOME TO STUDENT MENU.......\n\nAvailable actions : \n1. View All Courses\n2. Enroll (pick) New Course\n3. Drop a Course\n4. View Enrolled Courses\n5. Logout and Exit\n\nEnter Your Choice: ");
    rmsg(cfd,&msg); 

    choice = atoi(msg.body);
    switch (choice) {
    case 1:
        view_all_course(cfd);
        goto begin2;
        break;

    case 2:
	enroll_course(cfd, student_id);
	goto begin2;
        break;

    case 3:
    	drop_course(cfd, student_id);
        goto begin2;
        break;

    case 4:
    	view_enrolled_course(cfd, student_id);
    	goto begin2;
    	break;

    case 5:
    	wmsg(cfd, 0, 0, "");
    	exit(1);
    	break;

    default:
       	printf("Please enter correct choice...\n");
       	goto begin2;
    }
}

void faculty_menu(int cfd, int faculty_id)
{
    int choice;
    struct message msg;
    // Creating a Main
    // menu for the user
    begin3 :
    wmsg(cfd, 1, 0, "\n\n.......Welcome To Faculty Menu.......\n\nAvailable actions : \n1. View Offered Courses\n2. Add New Course\n3. Logout and Exit\n\nENTER YOUR CHOICE : ");
    rmsg(cfd,&msg); 

    choice = atoi(msg.body);
    switch (choice) {
    case 1:
        view_offered_course(cfd, faculty_id);
        goto begin3;
        break;

    case 2:
	add_course(cfd, faculty_id);
        goto begin3;
        break;

    case 3:
    	wmsg(cfd, 0, 0, "");
    	exit(1);
    	break;

    default:
       	printf("Please enter correct choice...\n");
       	goto begin3;
    }
}


void admin_menu(int cfd)
{
    int choice;
    struct message msg;
    // Creating a Main
    // menu for the user
    begin4 :
    wmsg(cfd, 1, 0, "\n\n.......Welcome To Admin Menu.......\n\nAvailable actions : \n1. Add Student\n2. View Student Details\n3. Add Faculty\n4. View Faculty Details\n5. Logout and Exit\n\nENTER YOUR CHOICE : ");
    rmsg(cfd,&msg); 

    choice = atoi(msg.body);
    switch (choice) {
    case 1:
        add_new_student(cfd);
        goto begin4;
        break;

    case 2:
	view_student(cfd);
	goto begin4;
        break;

    case 3:
    	add_new_faculty(cfd);
    	goto begin4;
    	break;

    case 4:
	view_faculty(cfd);
	goto begin4;
    	break;
    
    case 5:
    	wmsg(cfd, 0, 0, "");
    	exit(1);
    	break;
    	
    default:
       	printf("Please enter correct choice...\n");
       	goto begin4;
    }
}



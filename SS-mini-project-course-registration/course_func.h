
int add_new_course(int cfd, int faculty_id){
	int c_id;
	struct course new_course;
	struct message msg;

	//Getting details
	wmsg(cfd, 1, 1, "\nEnter Name: ");
	rmsg(cfd,&msg);
	strncpy(new_course.c_name,msg.body, sizeof(new_course.c_name));

	new_course.f_id = faculty_id;

	wmsg(cfd, 1, 0, "\nCredits: ");
	rmsg(cfd,&msg);
	new_course.credits = atoi(msg.body);

	wmsg(cfd, 1, 0, "\nTotal seats: ");
	rmsg(cfd,&msg);
	new_course.total_seats = atoi(msg.body);

	new_course.avail_seats = new_course.total_seats;
	new_course.active_status = 1;

	//Initializing...

	//Update to file
	wmsg(cfd, 0, 1, "\nGot Details ...");
	c_id=set_new_course(&new_course);
	if(c_id==-1){
		wmsg(cfd, 0, 1, "\nCannot Save Course...");
		return 0;
	}
	else{
		wmsg2(cfd, 0, 1, "\nCourse Created Successfully!\nNote: \nCourse ID", new_course.c_id);
	}
	return c_id;
}



void view_all_course(int cfd){
	int total = get_next_record(2);
//	wmsg2(cfd, 0, 1, "Total", total);
	if(total>0){
	//Getting details
		for(int i=1; i<total; i++){
			struct course cour=get_course(i);
			if(cour.active_status==1){
				wmsg2(cfd, 0, 1, "\nCourse", cour.c_id);
				wmsg3(cfd, 0, 1, "", cour.c_name);
			}
		}
	}
	else{
		wmsg(cfd, 0, 1, "\nNo course present");
	}
}

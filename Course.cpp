#include <iostream>
#include <string>
using namespace std;


class CourseSchedule {
private:
    string days;  

public:
    string time;  

  
    CourseSchedule() : days(""), time("") {}

   
    CourseSchedule(string d, string t) : days(d), time(t) {}

  
    void setDays(string d) {
        days = d;
    }

   
    void setTime(string t) {
        time = t;
    }

   
    string getDays() const {
        return days;
    }

   
    string getTime() const {
        return time;
    }

   
    ~CourseSchedule() {}
};


class Course {
private:
    string courseCode;    
    string courseTitle;  
    int creditHours;      
    CourseSchedule schedule; 
public:

    Course() : courseCode(""), courseTitle(""), creditHours(0) {}


    Course(string code, string title, int credits, CourseSchedule sched)
        : courseCode(code), courseTitle(title), creditHours(credits), schedule(sched) {
    }


    void setCourseCode(string code) {
        courseCode = code;
    }

    void setCourseTitle(string title) {
        courseTitle = title;
    }

    void setCreditHours(int credits) {
        creditHours = credits;
    }

    void setCourseSchedule(CourseSchedule s) {
        schedule = s;
    }

    
    string getCourseCode() const {
        return courseCode;
    }

    string getCourseTitle() const {
        return courseTitle;
    }

    int getCreditHours() const {
        return creditHours;
    }

    CourseSchedule getCourseSchedule() const {
        return schedule;
    }

    
    void displayCourseDetails() const {
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Title: " << courseTitle << endl;
        cout << "Credit Hours: " << creditHours << endl;
        cout << "Days: " << schedule.getDays() << endl;
        cout << "Time: " << schedule.getTime() << endl;
    }


    ~Course() {}
};


bool checkScheduleClash(const CourseSchedule& sched1, const CourseSchedule& sched2) {
    if (sched1.getDays() == sched2.getDays() && sched1.getTime() == sched2.getTime()) {
        return true;  
    }
    return false;  
}

int main() {
    const int MAX_COURSES = 10;
    Course courses[MAX_COURSES];  
    int totalCredits = 0;
    int courseCount = 0;
    bool scheduleClash = false;

    while (true) {
        string code, title, days, time;
        int credits;

      
        cout << "Enter course code: ";
        cin >> code;
        cout << "Enter course title: ";
        cin.ignore();  
        getline(cin, title);
        cout << "Enter credit hours: ";
        cin >> credits;
        cout << "Enter days (e.g., Mon, Wed, Fri): ";
        cin.ignore();  
        getline(cin, days);
        cout << "Enter time (e.g., 10:00 - 12:00): ";
        getline(cin, time);

        
        CourseSchedule schedule(days, time);

        
        Course course(code, title, credits, schedule);

       
        totalCredits += credits;
        if (totalCredits > 15) {
            cout << "You cannot take courses more than 15 credit hours in a semester." << endl;
            break;
        }

        
        for (int i = 0; i < courseCount; i++) {
            if (checkScheduleClash(courses[i].getCourseSchedule(), course.getCourseSchedule())) {
                cout << "Schedule clash detected with course: " << courses[i].getCourseCode() << endl;
                scheduleClash = true;
                break;
            }
        }

        if (scheduleClash) {
            break;
        }

     
        courses[courseCount++] = course;

        
        course.displayCourseDetails();

      
        char addMore;
        cout << "Do you want to add another course? (y/n): ";
        cin >> addMore;
        if (addMore == 'n' || addMore == 'N') {
            break;
        }
    }

    
    if (!scheduleClash && totalCredits <= 15) {
        cout << "Total credit hours: " << totalCredits << endl;
    }

    return 0;
}

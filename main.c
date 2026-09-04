#include <stdio.h>
#include "status.h"
#include "student.h"

int main() {
    printf("%d\n", ENROLLED);

    student_t student1;
    student1.name = "Farah";
    student1.status = ENROLLED;
    (void)student1;
    
    return 0;
}
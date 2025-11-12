#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
char userInputOfFilePath[1000];
char userInputOfFileName[1000];

FILE *createdFile;

void checkUserNamePass(char userInputOfFilePath[], char userInputOfIleName[]);

int main(void) {
  openlog("writer.c app", LOG_PID, LOG_LOCAL0);
  syslog(LOG_INFO, "PROGRAM STARTED");
  checkUserNamePass(userInputOfFilePath, userInputOfFileName);

  createdFile = fopen(
      "/home/kirk/Documents/assignment-2-KirSpaceB/assignments/output.txt",
      "w");
  if (createdFile == NULL) {
    syslog(LOG_ERR, "File is null");
    perror("CreatedFFile == Nullao");
    return 1;
  }
  fprintf(createdFile, "%s", userInputOfFileName);
  fclose(createdFile);
  closelog();
  return 0;
}

void checkUserNamePass(char userInputOfFilePath[], char userInputOfFileName[]) {
  if (userInputOfFilePath != NULL || userInputOfFileName != NULL) {

    printf("%s", "Please input the FilePath and FileName");
    scanf("%s", userInputOfFilePath);
    scanf("%s", userInputOfFileName);
  } else {
    syslog(LOG_ERR, "something went wrong in conditional");
    printf("%s", "Inputs are Null");
  }
}

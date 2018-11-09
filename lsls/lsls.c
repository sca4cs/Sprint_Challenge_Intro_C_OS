#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  char *dir;

  // Parse command line
  if (argc > 2) {
    printf("Please provide a single directory\n");
    exit(1);
  } else if (argc == 1) {
    dir = ".";
  } else {
    dir = argv[1];
  }

  // Open directory
  DIR *d = opendir(dir);

  if (d == NULL) { 
      fprintf(stderr, "Could not open directory\n");
      exit(1);
  }

  // Repeatly read and print entries
  struct dirent *ent;

  while ((ent = readdir(d)) != NULL) {
      printf("%s\n", ent->d_name);
  }

  // Close directory
  closedir(d);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void create_temp_file(const char *filename) {
    int fd = open(filename, O_RDWR | O_CREAT, S_IRWXU);

    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // 파일에 데이터 기록
    write(fd, "Secure Data\n", 12);

    // 의도적으로 잠시 대기 (경쟁 상태를 유발하기 위해)
    sleep(5);

    // 파일을 닫음
    close(fd);
}

int main() {
    const char *temp_file = "/tmp/race_condition_file";

    printf("Creating and writing to file: %s\n", temp_file);
    create_temp_file(temp_file);

    printf("File creation and writing complete.\n");

    return 0;
}

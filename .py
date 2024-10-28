import time
import os

filename = "/tmp/race_condition_file"

# 프로그램이 파일을 작성하기 전에 잠시 대기
time.sleep(2)

# 파일이 작성된 것을 확인하고 내용을 덮어쓰기
if os.path.exists(filename):
    print(f"Overwriting file: {filename}")
    with open(filename, "w") as f:
        f.write("Hacked Data\n")
else:
    print(f"File {filename} not found!")

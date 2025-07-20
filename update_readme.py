import datetime
import os

README_FILE = "README.md"

# 최근 수정된 cpp 파일 찾기
latest_cpp = None
for root, dirs, files in os.walk("."):
    for file in files:
        if file.endswith(".cpp"):
            path = os.path.join(root, file)
            if latest_cpp is None or os.path.getmtime(path) > os.path.getmtime(latest_cpp):
                latest_cpp = path

if not latest_cpp:
    print("추가된 cpp 파일을 찾지 못했습니다.")
    exit()

problem_num = os.path.splitext(os.path.basename(latest_cpp))[0]
topic = "알고리즘"
problem_link = f"https://www.acmicpc.net/problem/{problem_num}"
date = datetime.datetime.now().strftime("%Y.%m.%d")

# README 읽기
with open(README_FILE, "r", encoding="utf-8") as f:
    lines = f.readlines()

# 테이블에 새 줄 추가
for i, line in enumerate(lines):
    if "| 날짜 | 문제 번호 | 주제 | 파일 경로 | 문제 링크 |" in line:
        insert_pos = i + 2
        lines.insert(insert_pos, f"| {date} | {problem_num} | {topic} | `{latest_cpp[2:]}` | [🔗 링크]({problem_link}) |\n")
        break

# 덮어쓰기
with open(README_FILE, "w", encoding="utf-8") as f:
    f.writelines(lines)

print(f"README 업데이트 완료! {problem_num} 문제 기록이 추가되었습니다.")

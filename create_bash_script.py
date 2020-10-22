import json

with open('metadata.json') as f:
  question_list = json.load(f)

f = open('get_ac.sh', 'w')

for question in question_list['stat_status_pairs']:
    if question["status"] == "ac":
    	str1 = "leetcode submission {} -o submission/ \n".format(question['stat']["frontend_question_id"])
    	str2 = "sleep 1s\n"
    	f.write(str1)
    	f.write(str2)
f.close()
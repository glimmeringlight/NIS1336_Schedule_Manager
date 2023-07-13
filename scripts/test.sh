CURRENT_DIR=$(cd `dirname $0`; pwd)
ROOT_DIR=$(cd $(dirname $0);cd ..; pwd)


echo "This file is used to test basic function of Schedule program."

echo "--------------------------------------------------------------"
echo "[Task 1] Testing user registration and login."
cd $ROOT_DIR/bin
echo "[1.1] Register and then login"
./cli register -u test -p test
./cli login -u test -p test
echo "[1.2] Change user's password and try to login with new password"
./cli passwd -u test -p test -n newpwd
./cli login -u test -p newpwd

echo "--------------------------------------------------------------"
echo "[Task 2] Testing basic function."
./cli show -u test -p newpwd
echo "[2.1] Add a new task"
./cli add -u test -p newpwd -n TestTask -o HIGH -c LIFE -r 2025-01-01,00:00:00 -s 2025-01-02,00:00:00 -d "Just for test"
./cli show -u test -p newpwd
echo "[2.2] Modify an existing task."
./cli alt -u test -p newpwd -i 1 -n Newname
echo "[2.2] Add a task which has existing name"
./cli add -u test -p newpwd -n TestTask -o HIGH -c LIFE -r 2025-01-01,00:00:00 -s 2025-01-02,00:00:00 -d "Just for test2"
echo "[2.3] Add a task which has invalid time"
./cli add -u test -p newpwd -n "Test Time" -o HIGH -c LIFE -r 2020-01-01,00:00:00 -s 2020-01-02,00:00:00 -d "Just for test"
echo "[2.4] Delete the task whose id = 1"
./cli del -u test -p newpwd -i 1
./cli show -u test -p newpwd

echo "--------------------------------------------------------------"
echo "[Finish testing]"
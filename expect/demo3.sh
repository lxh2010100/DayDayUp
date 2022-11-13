#!/bin/bash
user="luxihua"
host="192.168.0.109"
password="cc86c854"

/usr/bin/expect <<EOF
set time 20
spawn ssh $user@$host
expect "*Password:" { send "$password\r" }
expect "*$"
send "pwd\r"
expect "*$"
send "df -h\r"
expect "*$"
send "exit\r"
interact
expect eof
EOF

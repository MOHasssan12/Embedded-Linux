# Section 2 :

### 1.Create a supplementary (Secondary) group called pgroup with group ID of 30000

sudo groupadd -g 30000 pgroup

### 2.Lock any user created account so he can't log in

sudo passwd -l username

### 3.Delete User Account

sudo userdel username

### 4.Delete Group Account

sudo groupdel groupname


### 5.State the difference between adduser and useradd with example shown.

adduser: This is a higher-level utility that provides a friendlier interactive interface for creating new users. It automates several tasks that are commonly performed when setting up a new user, such as creating a home directory, setting up the environment, prompting for user information, and managing defaults.

sudo adduser hussein

useradd: This is a lower-level command-line utility that directly manipulates the system files (/etc/passwd, /etc/shadow, etc.) to create a new user account. It requires more options to be specified explicitly for tasks such as setting the home directory, default shell, and initial password.

sudo useradd -m -s /bin/bash -U hussein





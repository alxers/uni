1. File -> New Project
2. Choose "Maven", check "Create from archetype" checkbox, choose "org.apache.maven.archetypes:maven-archetype-webapp" ![link](readme/1.png)
3. Enter project name, click "Next", click "Finish".
4. Add servlet and log4j dependencies in "pom.xml" file, then load maven changes (Ctrl+Shift+O or by clicking an icon). ![link](readme/2.png)
5. Click "Add Configuration" (top right corner) ![link](readme/3.png)
Then click "+" icon and choose "Tomcat Server -> Local" (Tomcat server should be installed already) ![link](readme/4.png)
You can download Tomcat here: [https://tomcat.apache.org/download-90.cgi](https://tomcat.apache.org/download-90.cgi)
6. Click "Configure", choose the directory where Tomcat Server is installed ![link](readme/5.png)
7. Click "Fix" and choose the first option ![link](readme/6.png)
then click "Apply" and "OK".
8. Now you should be able to run the project ![link](readme/7.png)
If you're getting errors "Address localhost:xxxx already in use" go back to step 5, and choose another port.

Sometimes you can get Tomcat shutdown error.
In that case you should go to "C:\Program Files\Apache Software Foundation\Tomcat 9.0\conf", open "server.xml" and change **Server port="-1" shutdown="SHUTDOWN"** to **Server port="1" shutdown="SHUTDOWN"**
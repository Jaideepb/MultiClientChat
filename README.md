Description :
--------------
This project is an implementation of Chat client.

Implementation:
---------------

Details:
1.User registers
2.Authenticates/login
3.Check all logged-in users, along with their status
4.Send message to particular user
5.Send message to a group of user's
6.Broadcast message
7.Logout

Server: 
- Stores all the registered users.
- Authenticates the user.
- Send the list of logged-in users when requested.

Client:
- Register/Login
	-> Register: Inputs username/password and register in server.
	-> Login   : Authenticates with the server.
- Set status(Optional): By default status will be Available
- Send message to particular user
- Send message to set of user's
- Broadcast message to all users
- Send file to a user or set of users. 

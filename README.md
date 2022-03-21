# SoftwareTesting

An application which simulates the development and testing of a software application, as follows:

The information about the development team is read from a text file, Each member of the team- USER has a name and a type(tester/programmer).
Another file contains information about the issues reported by the testers. Each Issue has a description, a status (open/closed), a reporter name and a solver name.

When the application is launched, a new window is created for each user, having as title the user's name and type (tester or programmer).
Each window will show all the issues, with their description, status, reporter and solver, sorted by status and by description. 

Only testers can report issues, by inputting the issue's description and pressing a button "Add". The issue's reporter wil be automatically set to
the name of the tester who added it. This operation fails if the description is empty or if there is another issue with the same description.
The user will be informed if the operation fails.

Both programmers and users cand remove issues. An issue can only be removed is its status is **closed**.

Only programmers cand resolve issues, by sekecting the issue and pressing the button "Resolve". This button is activated only if the status of the selected issue is **open**.
When a issue is resolved, the name of the issue's solver is automatically updated to the name of the programmer who solved it.

Using the Observer Design Pattern, when a modification is made by any user, all the other users will see the modified list.
Only ehen the application is closed, the issues file will be updated.

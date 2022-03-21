#include "SoftwareTesting.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Service.h"
#include "UserGUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IssueRepo* ir = new IssueRepo{"issues.txt"};
    UserRepo* ur = new UserRepo{"users.txt"};
    ServiceI* is=new ServiceI(ir);
    ServiceU* us=new ServiceU(ur);
    gui g(us, is);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, [ir]() { ir->save(); });
    return a.exec();

    delete is;
    delete us;
}

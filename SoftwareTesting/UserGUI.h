#pragma once
#include <qwidget.h>
#include "Observer.h"
#include <QListWidget>
#include <qlineedit.h>
#include <QPushButton>
#include "Service.h"

class Usersgui: public QWidget, public Observer
{
private:
	std::string name;
	std::string type;
	ServiceI* serv;
	QListWidget* lst;
	QPushButton* addButton;
	QPushButton* removeButton; 
	QPushButton* resolveButton;
	QLineEdit* addEdit;
public:
	Usersgui(const std::string& name, const std::string& type, ServiceI* s) : name(name), type(type), serv(s) { serv->addObserver(this); gui_init(); addConnections(); update(); }
	~Usersgui() { this->serv->removeObserver(this); }
	void gui_init();
	void update();
	void addConnections();
	int getSelectedIdx();
	void addHandler();
	void removeHandler();
	void resolveHandler();
	void setEnable();
};

class gui : public QWidget {
private:
	ServiceI* issueServ;
	ServiceU* userServ;
public:
	gui(ServiceU* u, ServiceI* i) :userServ(u), issueServ(i) { create_user_tabs(); }
	void create_user_tabs();
};
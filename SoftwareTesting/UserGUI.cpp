#include "UserGUI.h"
#include <QHBoxLayout>
#include <qmessagebox.h>

void Usersgui::gui_init()
{
	QHBoxLayout* layout = new QHBoxLayout{ this };
	this->setWindowTitle(QString::fromStdString(this->name + ": " + this->type));
	this->lst = new QListWidget{};
	this->lst->setSelectionMode(QAbstractItemView::SingleSelection);
	layout->addWidget(this->lst);

	QWidget* rightSide = new QWidget{};
	QVBoxLayout* vLayout = new QVBoxLayout{ rightSide };


	//Buttons
	QWidget* buttonsWidget = new QWidget{};
	QHBoxLayout* hLayout = new QHBoxLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->removeButton = new QPushButton("Remove");
	this->resolveButton = new QPushButton("Resolve");
	this->addEdit = new QLineEdit{};
	if (this->type == "tester") {
		hLayout->addWidget(this->addButton);
		hLayout->addWidget(this->addEdit);
	}
	hLayout->addWidget(this->removeButton);
	if(this->type=="programmer")
		hLayout->addWidget(this->resolveButton);
	this->resolveButton->setDisabled(true);

	vLayout->addWidget(buttonsWidget);

	//Add rightside to general layout
	layout->addWidget(rightSide);

	this->serv->sort();
}

void Usersgui::update()
{
	// clear the list, if there are elements in it
	if (this->lst->count() > 0)
		this->lst->clear();

	for (const auto& e : this->serv->getElems()) {
		QString itemInList = QString::fromStdString(e.getDescription()) + " " + QString::fromStdString(e.getStatus())+ " " + QString::fromStdString(e.getReporter())+" " + QString::fromStdString(e.getSolver());
		QFont f{ "Verdana", 15, };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);;
		this->lst->addItem(item);
	}
}

void Usersgui::addConnections()
{
	QObject::connect(this->lst, &QListWidget::itemSelectionChanged, this, [this]() {this->setEnable(); });
	QObject::connect(this->addButton, &QPushButton::clicked, this, &Usersgui::addHandler);
	QObject::connect(this->removeButton, &QPushButton::clicked, this, &Usersgui::removeHandler);
	QObject::connect(this->resolveButton, &QPushButton::clicked, this, &Usersgui::resolveHandler);
}

int Usersgui::getSelectedIdx()
{
	int idx;
	if (this->lst->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->lst->selectionModel()->selectedIndexes();
	if (index.size() == 0)
		return -1;

	idx = index.at(0).row();

	if (idx >= this->serv->getElems().size())
		return -1;

	return idx;
}

void Usersgui::addHandler()
{
	//only testers
	try {
		if (this->type == "tester") {
			if (this->addEdit->text().toStdString() != "") { 
				Issue i = Issue(this->addEdit->text().toStdString(), "open", this->name, "");
				this->serv->add(i);
				this->serv->sort();
				this->serv->notify();
			}
			else {
				QMessageBox* msgBox;
				msgBox->warning(this->lst, "Error", "Empty description!");
			}
		}
	}
	catch (const std::exception& ex) {
		QMessageBox* msgBox;
		msgBox->warning(this->lst, "Error", "The following issue was already added");
	}
}

void Usersgui::removeHandler()
{
	//both testers & programmers
	int idx = getSelectedIdx();
	if (idx != -1) {
		Issue i = this->serv->getElems()[idx];
		if (i.getStatus() == "closed") {
			this->serv->remove(i);
			this->serv->notify();
		}
	}
}

void Usersgui::resolveHandler()
{
	//only programmers
	int idx = getSelectedIdx();
	if (idx != -1) {
		Issue i = this->serv->getElems()[idx];
		if (i.getStatus() == "open") {
			this->serv->getElems()[idx].setSolver(this->name);
			this->serv->getElems()[idx].setStatus("closed");
			this->serv->notify();
		}
	}
}

void Usersgui::setEnable()
{
	int idx = getSelectedIdx();
	if (idx != -1) {
		Issue i = this->serv->getElems()[idx];
		if (i.getStatus() == "open") {
			this->resolveButton->setEnabled(true);
		}
		else {
			this->resolveButton->setDisabled(true);
		}
	}
}

void gui::create_user_tabs()
{
	for (const auto& e : this->userServ->getElems()) {
		Usersgui* g=new Usersgui(e.getName(), e.getType(), this->issueServ);
		g->show();
	}
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_addItemPB_clicked()
{
    try
    {
        std::string ID, Location, Description = "";
        ID= ui->iDLineEdit->text().toStdString();
        Location = ui->locationLineEdit->text().toStdString();
        Description = ui->descriptionLineEdit->text().toStdString();
        auto item = std::make_shared<StoredItem>(ID, Description, Location);
        manager.addItem(item);
        ui->sortedItemsTE->setText(QString::fromStdString(manager.listItemsByDescription()));
    }
    catch (const DuplicateItemException& e)
    {
        QMessageBox::about(this, "DuplicateItemException", e.what());
        ui->ErrorDIalogueTE->setText(QString::fromStdString(e.what()));
    }
    catch (...) // catches any other unknown errors
    {
        QMessageBox::about(this, "Unknown", "An unknown error occurred.");
        ui->ErrorDIalogueTE->setText("An unknown error occurred.");
    }
}


void MainWindow::on_findByIDPB_clicked()
{
    std::string ID = "";
    ID = ui ->findByIDLE->text().toStdString();

    try
    {
        std::shared_ptr<StoredItem> foundItem = manager.findById(ID);
        ui->foundAtTE->setText(QString::fromStdString("ID: " + ID + "\nfound at location: " + foundItem->getLocation()));


    }
    catch (const ItemNotFoundException& e)
    {
        QMessageBox::about(this, "ItemNotFoundException", e.what());
        ui->ErrorDIalogueTE->setText(QString::fromStdString(e.what()));
    }
    catch (...) // catches any other unknown errors
    {
        QMessageBox::about(this, "Unknown", "An unknown error occurred.");
        ui->ErrorDIalogueTE->setText("An unknown error occurred.");
    }

}


void MainWindow::on_removeByIDPB_clicked()
{
    std::string ID = "";
    ID = ui ->removeByIDLE->text().toStdString();
    try
    {
        manager.removeItem(ID);
        ui->foundAtTE->setText(QString::fromStdString("Removed ID: " + ID));
        ui->sortedItemsTE->setText(QString::fromStdString(manager.listItemsByDescription()));

    }
    catch (const ItemNotFoundException& e)
    {
        QMessageBox::about(this, "ItemNotFoundException", e.what());
        ui->ErrorDIalogueTE->setText(QString::fromStdString(e.what()));
    }
    catch (...) // catches any other unknown errors
    {
        QMessageBox::about(this, "Unknown", "An unknown error occurred.");
        ui->ErrorDIalogueTE->setText("An unknown error occurred.");
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About", "Created by Aithy - GUI Assignment");
}


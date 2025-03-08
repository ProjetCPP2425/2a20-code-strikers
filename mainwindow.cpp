#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlError>
#include <QPixmap>
#include <QDebug>
#include <QRandomGenerator>
#include "equipe.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    update(false),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    QPixmap pix("C:/logo");
    ui->logo->setPixmap(pix);

    QWidget *um = ui->upper_menu;
    um->setStyleSheet(
        "background-color: black;"
        "color: white;"
        "QHeaderView::section {"
        "background-color: black;"
        "color: white;"
        "font-size: 16px;"
        "font-weight: bold;"
        "text-align: center;"
        "padding: 5px;"

        "}"

        "QTextEdit { background-color: black; color: white; }"

        );
    ui->
        tableView->setStyleSheet(
        "QTableView {"
        "    background-color: white;"  // Table background color
        "    color: #333333;"            // Text color (dark gray for readability)
        "    border: 1px solid #4A90E2;" // Border color (light blue)
        "    font-size: 14px;"           // Font size
        "    selection-background-color: #4A90E2;" // Selected row background (blue)
        "    selection-color: white;"    // Selected text color (white)
        "    alternate-background-color: #f7f7f7;" // Alternating row colors
        "    gridline-color: #e0e0e0;"  // Gridline color (light gray)
        "}"
        "QHeaderView::section {"
        "    background-color: #4A90E2;" // Header background color (blue)
        "    color: white;"              // Header text color (white)
        "    padding: 8px;"              // Padding for header cells
        "    font-weight: bold;"         // Bold header text
        "    text-align: center;"        // Center-align header text
        "}"
        "QScrollBar:vertical {"
        "    background-color: #f7f7f7;" // Scrollbar background color (lighter gray)
        "    border: none;"               // No border
        "    width: 10px;"                // Set the width of the vertical scrollbar
        "    margin: 0px 0px 0px 0px;"    // Margin around the scrollbar
        "    border-radius: 5px;"         // Rounded corners for the scrollbar itself
        "}"
        "QScrollBar::handle:vertical {"
        "    background-color: #4A90E2;" // Handle (slider) color (blue)
        "    min-height: 40px;"           // Minimum height for the handle
        "    border-radius: 6px;"         // Rounded corners for the handle
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "    border: none;"               // Remove borders for the arrows
        "    background: none;"           // Remove background for the arrows
        "    width: 0px;"                 // Remove the width of the arrows
        "    height: 0px;"                // Remove the height of the arrows
        "}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
        "    background: none;"           // Remove the background color for the add/sub page
        "}"
        "QScrollBar:horizontal {"
        "    background-color: #f7f7f7;" // Horizontal scrollbar background color (lighter gray)
        "    border: none;"               // No border
        "    height: 10px;"               // Set the height of the horizontal scrollbar
        "    margin: 0px 0px 0px 0px;"    // Margin around the scrollbar
        "    border-radius: 5px;"         // Rounded corners for the scrollbar itself
        "}"
        "QScrollBar::handle:horizontal {"
        "    background-color: #4A90E2;" // Handle (slider) color (blue)
        "    min-width: 40px;"            // Minimum width for the handle
        "    border-radius: 6px;"         // Rounded corners for the handle
        "}"
        "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
        "    border: none;"               // Remove borders for the arrows
        "    background: none;"           // Remove background for the arrows
        "    width: 0px;"                 // Remove the width of the arrows
        "    height: 0px;"                // Remove the height of the arrows
        "}"
        "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {"
        "    background: none;"           // Remove the background color for the add/sub page
        "}"

        );

    ui->IdTextEdit->setVisible(false);




    //Setup database connection
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("tournois");
    db.setUserName("Montassar");
    db.setPassword("riahi123");

    if (db.open()) {
        qDebug() << "✅ Database connected successfully!";
    } else {
        qDebug() << "❌ Database connection failed: " << db.lastError().text();
    }

    equipe e;
    e.readData(ui->tableView,db);



}

MainWindow::~MainWindow()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "🔌 Database connection closed.";
    }
    delete ui;
}

void MainWindow::on_pushButton_17_clicked()
{
    QDate date = QDate::fromString(ui->date_c->toPlainText(), "yyyy-MM-dd");
    if(!update)
    {


        equipe eq(0,
                  ui->nom_eq->toPlainText(),
                  date,
                  ui->entreneur->toPlainText(),
                  ui->categorie_2->toPlainText(),
                  ui->nb_vict->toPlainText().toInt(),
                  ui->nb_def->toPlainText().toInt(),
                  ui->nb_null->toPlainText().toInt(),
                  ui->nb_pnt->toPlainText().toInt(),
                  ui->email->toPlainText()
                  );
        eq.console_equipe();

        eq.insertData(db);
        eq.readData(ui->tableView,db);
    }else
    {
        equipe eq(ui->IdTextEdit->toPlainText().toInt(),
                  ui->nom_eq->toPlainText(),
                  date,
                  ui->entreneur->toPlainText(),
                  ui->categorie_2->toPlainText(),
                  ui->nb_vict->toPlainText().toInt(),
                  ui->nb_def->toPlainText().toInt(),
                  ui->nb_null->toPlainText().toInt(),
                  ui->nb_pnt->toPlainText().toInt(),
                  ui->email->toPlainText()
                  );
        eq.updateData(ui->IdTextEdit->toPlainText().toInt(),db);
        eq.readData(ui->tableView,db);
    }



}




//cancel button
void MainWindow::on_pushButton_19_clicked()
{
    QDate date = QDate::fromString(ui->date_c->toPlainText(), "yyyy-MM-dd");
    equipe eq(ui->IdTextEdit->toPlainText().toInt(),
              ui->nom_eq->toPlainText(),
              date,
              ui->entreneur->toPlainText(),
              ui->categorie_2->toPlainText(),
              ui->nb_vict->toPlainText().toInt(),
              ui->nb_def->toPlainText().toInt(),
              ui->nb_null->toPlainText().toInt(),
              ui->nb_pnt->toPlainText().toInt(),
              ui->email->toPlainText()
              );

    eq.updateData(eq.getId(),db);
    eq.readData(ui->tableView,db);
    update=false;
}

void MainWindow::setData(QString a,QString b,QString c,QString d,QString e,QString f,QString g,QString h,QString i,QString j){

    ui->IdTextEdit->setPlainText(a);
    ui->nom_eq->setPlainText(b);
    ui->date_c->setPlainText(c);
    ui->entreneur->setPlainText(d);
    ui->categorie_2->setPlainText(e);
    ui->nb_vict->setPlainText(f);
    ui->nb_def->setPlainText(g);
    ui->nb_null->setPlainText(h);
    ui->nb_pnt->setPlainText(i);
    ui->email->setPlainText(j);
}





void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tableView->model();
    // Cast the model to QSqlTableModel for better access to the specific model features
    int rowIndex = index.row();


    setData(model->data(model->index(rowIndex,0)).toString(),
            model->data(model->index(rowIndex,1)).toString(),
            model->data(model->index(rowIndex,2)).toString(),
            model->data(model->index(rowIndex,3)).toString(),
            model->data(model->index(rowIndex,4)).toString(),
            model->data(model->index(rowIndex,5)).toString(),
            model->data(model->index(rowIndex,6)).toString(),
            model->data(model->index(rowIndex,7)).toString(),
            model->data(model->index(rowIndex,8)).toString(),
            model->data(model->index(rowIndex,9)).toString()
            );

    update =true;

    // Iterate through columns to get the data for the row

}


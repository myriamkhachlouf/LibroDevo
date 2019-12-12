#include "recherche_emp.h"
#include "ui_recherche_emp.h"
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include <QDate>

Recherche_Emp::Recherche_Emp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recherche_Emp)
{
    ui->setupUi(this);
}

Recherche_Emp::~Recherche_Emp()
{
    delete ui;
}

void Recherche_Emp::on_pushButton_clicked()
{
    QString id = ui->lineEdit_rechemp->text();

        ui->tabemp->setModel(tmpemp.recherche_empa(id));

}

void Recherche_Emp::on_pushButton_2_clicked()
{
    QString id = ui->lineEdit_rechemp->text();

        ui->tabemp->setModel(tmpemp.recherche_empd(id));

}

void Recherche_Emp::on_pdf_2_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabemp->model()->rowCount();
        const int columnCount = ui->tabemp->model()->columnCount();
        QString TT = QDate::currentDate().toString("yyyy/MM/dd");
        out <<"<html>\n"
              "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            << "<title>ERP - COMmANDE LIST<title>\n "
            << "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<h1 style=\"text-align: center;\"><strong> ******LISTE DES Factures ****** "+TT+"</strong></h1>"
            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
              "</br> </br>";
        // headers
        out << "<thead><tr bgcolor=#d6e5ff>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabemp->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabemp->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabemp->isColumnHidden(column)) {
                    QString data =ui->tabemp->model()->data(ui->tabemp->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
        if (daddy->exec() == QDialog::Accepted) {
            document->print(&printer);
        }

        delete document;
}

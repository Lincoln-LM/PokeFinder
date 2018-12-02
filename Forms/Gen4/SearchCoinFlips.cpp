/*
 * This file is part of PokéFinder
 * Copyright (C) 2017 by Admiral_Fish, bumba, and EzPzStreamz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "SearchCoinFlips.hpp"
#include "ui_SearchCoinFlips.h"

SearchCoinFlips::SearchCoinFlips(const QVector<DateTime> &model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchCoinFlips)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);

    data = model;
    ui->labelPossibleResults->setText(tr("Possible Results: ") + QString::number(model.size()));
}

SearchCoinFlips::~SearchCoinFlips()
{
    delete ui;
}

QVector<bool> SearchCoinFlips::possibleResults()
{
    return possible;
}

void SearchCoinFlips::on_pushButtonHeads_clicked()
{
    QString string = ui->lineEditFlips->text();

    if (string.isEmpty())
        string = "H";
    else
        string += ", H";

    ui->lineEditFlips->setText(string);
}

void SearchCoinFlips::on_pushButtonTails_clicked()
{
    QString string = ui->lineEditFlips->text();

    if (string.isEmpty())
        string = "T";
    else
        string += ", T";

    ui->lineEditFlips->setText(string);
}

void SearchCoinFlips::on_lineEditFlips_textChanged(const QString &arg1)
{
    QStringList results = arg1.split(",", QString::SkipEmptyParts);

    int num = 0;

    possible.clear();
    for (auto &i : data)
    {
        QStringList compare = Utilities::coinFlips(i.getSeed(), 15).split(",", QString::SkipEmptyParts);

        bool pass = true;
        for (int j = 0; j < results.size(); j++)
        {
            if (results[j] != compare[j])
            {
                pass = false;
                break;
            }
        }
        possible.append(pass);
        if (pass)
            num++;
    }

    ui->labelPossibleResults->setText(tr("Possible Results: ") + QString::number(num));
}

void SearchCoinFlips::on_pushButtonOkay_clicked()
{
    done(QDialog::Accepted);
}

void SearchCoinFlips::on_pushButtonCancel_clicked()
{
    done(QDialog::Rejected);
}

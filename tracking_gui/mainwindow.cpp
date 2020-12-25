#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,
                       std::vector<int> inRangeData,
                       std::function<void(std::shared_ptr<five_axis_tracking::tracking>)> process_cb)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , process_cb_(process_cb)
{
    ui->setupUi(this);

    slider_value_init(ui->huHorizontalSlider, inRangeData[0]);
    slider_value_init(ui->hlHorizontalSlider, inRangeData[1]);
    slider_value_init(ui->suHorizontalSlider, inRangeData[2]);
    slider_value_init(ui->slHorizontalSlider, inRangeData[3]);
    slider_value_init(ui->vuHorizontalSlider, inRangeData[4]);
    slider_value_init(ui->vlHorizontalSlider, inRangeData[5]);

    slider_value_init(ui->minDistanceHorizontalSlider, inRangeData[6]);
    slider_value_init(ui->cannyThresholdHorizontalSlider, inRangeData[7]);
    slider_value_init(ui->accumulatorThresholdHorizontalSlider, inRangeData[8]);

    msg_ = std::make_shared<five_axis_tracking::tracking>();
    _timerId = startTimer(50); //ms
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *)
{
    msg_->hue_upper = ui->huHorizontalSlider->value();
    msg_->hue_lower = ui->hlHorizontalSlider->value();

    msg_->saturation_upper = ui->suHorizontalSlider->value();
    msg_->saturation_lower = ui->slHorizontalSlider->value();

    msg_->value_upper = ui->vuHorizontalSlider->value();
    msg_->value_lower = ui->vlHorizontalSlider->value();

    msg_->hough_min_dist = ui->minDistanceHorizontalSlider->value();
    msg_->hough_param_1 = ui->cannyThresholdHorizontalSlider->value();
    msg_->hough_param_2 = ui->accumulatorThresholdHorizontalSlider->value();

    msg_->show_hough_depth_image = ui->showHoughDepthImageCheckBox->isChecked();
    msg_->show_hsv_window = ui->showHSVWindowCheckBox->isChecked();

    process_cb_(msg_);
}

void MainWindow::on_huHorizontalSlider_valueChanged(int value)
{
    process_slider_value_change(ui->huLabel, "Hue upper", value);
}

void MainWindow::on_hlHorizontalSlider_valueChanged(int value)
{
    process_slider_value_change(ui->hlLabel, "Hue lower", value);
}

void MainWindow::on_suHorizontalSlider_valueChanged(int value)
{
    process_slider_value_change(ui->suLabel, "Saturation upper", value);
}

void MainWindow::on_slHorizontalSlider_valueChanged(int value)
{
    process_slider_value_change(ui->slLabel, "Saturation lower", value);
}

void MainWindow::on_vuHorizontalSlider_valueChanged(int value)
{
    process_slider_value_change(ui->vuLabel, "Value upper", value);
}

void MainWindow::on_vlHorizontalSlider_valueChanged(int value)
{
    process_slider_value_change(ui->vlLabel, "Value lower", value);
}

void MainWindow::on_minDistanceHorizontalSlider_valueChanged(int value)
{
    process_slider_value_change(ui->minDistLabel, "Min distance", value);
}

void MainWindow::on_cannyThresholdHorizontalSlider_valueChanged(int value)
{
    process_slider_value_change(ui->cannyThresholdLabel, "Canny threshold", value);
}

void MainWindow::on_accumulatorThresholdHorizontalSlider_valueChanged(int value)
{
    process_slider_value_change(ui->accumulatorThresholdLabel, "Accumulator threshold", value);
}

void MainWindow::slider_value_init(QSlider *slider, int value)
{
    slider->setValue(value);
}

void MainWindow::process_slider_value_change(QLabel *label, QString text, int value)
{
    QString label_text = QString("%1 (%2)").arg(text).arg(value,3, 10);
    label->setText(label_text);
}

void MainWindow::on_showHoughCirclesCheckBox_toggled(bool checked)
{
}



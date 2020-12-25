#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <msg/tracking.h>

#include <QMainWindow>
#include <QSlider>
#include <QLabel>

#include <functional>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, std::vector<int> inRangeData, std::function<void(std::shared_ptr<five_axis_tracking::tracking>)> process_cb);
    ~MainWindow();

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void on_huHorizontalSlider_valueChanged(int value);
    void on_hlHorizontalSlider_valueChanged(int value);
    void on_suHorizontalSlider_valueChanged(int value);
    void on_slHorizontalSlider_valueChanged(int value);
    void on_vuHorizontalSlider_valueChanged(int value);
    void on_vlHorizontalSlider_valueChanged(int value);
    void on_showHoughCirclesCheckBox_toggled(bool checked);

    void on_minDistanceHorizontalSlider_valueChanged(int value);

    void on_cannyThresholdHorizontalSlider_valueChanged(int value);

    void on_accumulatorThresholdHorizontalSlider_valueChanged(int value);

private:
    void slider_value_init(QSlider *slider, int value);
    void process_slider_value_change(QLabel *label, QString text, int value);

private:
    Ui::MainWindow *ui;
    std::function<void(std::shared_ptr<five_axis_tracking::tracking>)> process_cb_;
    std::shared_ptr<five_axis_tracking::tracking> msg_;
    int _timerId;
};
#endif // MAINWINDOW_H

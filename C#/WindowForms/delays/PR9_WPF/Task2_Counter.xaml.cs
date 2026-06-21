using System;
using System.ComponentModel;
using System.Threading;
using System.Windows;

namespace PR9;

public partial class Task2_Counter : Window
{
    private readonly BackgroundWorker _worker = new() { WorkerReportsProgress = true, WorkerSupportsCancellation = true };
    private const long Max = 1_000_000;

    public Task2_Counter()
    {
        InitializeComponent();
        _worker.DoWork          += Worker_DoWork;
        _worker.ProgressChanged += Worker_ProgressChanged;
        _worker.RunWorkerCompleted += (_, _) =>
        {
            btnStart.IsEnabled = true;
            btnStop.IsEnabled  = false;
        };
    }

    private void Worker_DoWork(object? sender, DoWorkEventArgs e)
    {
        // Счёт туда и обратно
        for (long i = 0; i <= Max; i++)
        {
            if (_worker.CancellationPending) { e.Cancel = true; return; }
            if (i % 1000 == 0)
                _worker.ReportProgress((int)(i * 100 / Max), i);
        }
        for (long i = Max; i >= 0; i--)
        {
            if (_worker.CancellationPending) { e.Cancel = true; return; }
            if (i % 1000 == 0)
                _worker.ReportProgress((int)(i * 100 / Max), i);
        }
    }

    private void Worker_ProgressChanged(object? sender, ProgressChangedEventArgs e)
    {
        long val = (long)e.UserState!;
        lblCount.Content    = val.ToString("N0");
        progressBar.Value   = val;
    }

    private void Start_Click(object sender, RoutedEventArgs e)
    {
        if (!_worker.IsBusy)
        {
            _worker.RunWorkerAsync();
            btnStart.IsEnabled = false;
            btnStop.IsEnabled  = true;
        }
    }

    private void Stop_Click(object sender, RoutedEventArgs e)
    {
        _worker.CancelAsync();
    }

    private void Window_Closing(object? sender, CancelEventArgs e)
    {
        _worker.CancelAsync();
    }
}

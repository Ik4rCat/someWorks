using System;
using System.Drawing;
using System.Windows.Forms;

/// <summary>
/// Задание 1: Иерархическое управление TreeView + ListView.
/// Добавление/удаление категорий и элементов.
/// </summary>
public class Task1_TreeListView : Form
{
    private readonly TreeView  treeView;
    private readonly ListView  listView;
    private readonly TextBox   txtInput;

    public Task1_TreeListView()
    {
        Text = "Задание 1: TreeView + ListView";
        ClientSize = new Size(700, 480);
        StartPosition = FormStartPosition.CenterScreen;
        MinimumSize = new Size(600, 400);

        // ---- TreeView ----
        treeView = new TreeView
        {
            Location = new Point(8, 8),
            Size = new Size(200, 420),
            Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Bottom
        };

        // Заполнение тестовыми данными
        var nodeAnimals = new TreeNode("Животные");
        nodeAnimals.Nodes.AddRange(new[] { new TreeNode("Кот"), new TreeNode("Собака"), new TreeNode("Птица") });

        var nodePlants = new TreeNode("Растения");
        nodePlants.Nodes.AddRange(new[] { new TreeNode("Роза"), new TreeNode("Кактус") });

        var nodeTech = new TreeNode("Техника");
        nodeTech.Nodes.AddRange(new[] { new TreeNode("Компьютер"), new TreeNode("Телефон"), new TreeNode("Планшет") });

        treeView.Nodes.AddRange(new[] { nodeAnimals, nodePlants, nodeTech });
        treeView.AfterSelect += OnTreeSelect;

        // ---- ListView ----
        listView = new ListView
        {
            Location = new Point(220, 8),
            Size = new Size(390, 340),
            View = View.Details,
            FullRowSelect = true,
            GridLines = true,
            Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right | AnchorStyles.Bottom
        };
        listView.Columns.Add("Элемент", 200);
        listView.Columns.Add("Категория", 180);

        // ---- Ввод / кнопки ----
        var lblInput = new Label { Text = "Название:", Location = new Point(220, 360), AutoSize = true };
        txtInput = new TextBox { Location = new Point(220, 380), Size = new Size(200, 26) };

        var btnAddCat = new Button { Text = "+ Категория", Location = new Point(220, 412), Size = new Size(110, 34) };
        var btnAddItem = new Button { Text = "+ Элемент",   Location = new Point(340, 412), Size = new Size(110, 34) };
        var btnDel     = new Button { Text = "Удалить",     Location = new Point(460, 412), Size = new Size(110, 34) };

        btnAddCat.Click  += AddCategory;
        btnAddItem.Click += AddItem;
        btnDel.Click     += DeleteSelected;

        Controls.AddRange(new Control[]
        {
            treeView, listView,
            lblInput, txtInput,
            btnAddCat, btnAddItem, btnDel
        });

        // Показать первый узел
        treeView.SelectedNode = treeView.Nodes[0];
    }

    private void OnTreeSelect(object? sender, TreeViewEventArgs e)
    {
        listView.Items.Clear();
        if (e.Node == null) return;

        // Показать дочерние узлы в ListView
        foreach (TreeNode child in e.Node.Nodes)
        {
            var item = new ListViewItem(child.Text);
            item.SubItems.Add(e.Node.Text);
            item.Tag = child;
            listView.Items.Add(item);
        }
    }

    private void AddCategory(object? sender, EventArgs e)
    {
        string name = txtInput.Text.Trim();
        if (string.IsNullOrEmpty(name)) return;
        treeView.Nodes.Add(new TreeNode(name));
        txtInput.Clear();
    }

    private void AddItem(object? sender, EventArgs e)
    {
        string name = txtInput.Text.Trim();
        if (string.IsNullOrEmpty(name)) return;
        var parent = treeView.SelectedNode;
        if (parent == null) { MessageBox.Show("Выберите категорию."); return; }

        // Добавляем в корневой узел (не в дочерний)
        var root = parent.Parent ?? parent;
        root.Nodes.Add(name);
        treeView.SelectedNode = root; // обновляем ListView
        txtInput.Clear();
    }

    private void DeleteSelected(object? sender, EventArgs e)
    {
        if (listView.SelectedItems.Count > 0)
        {
            // Удалить из TreeView
            if (listView.SelectedItems[0].Tag is TreeNode node)
                node.Remove();
            // Обновить ListView
            treeView.SelectedNode = treeView.SelectedNode; // trigger refresh
            OnTreeSelect(null, new TreeViewEventArgs(treeView.SelectedNode!));
        }
        else if (treeView.SelectedNode != null)
        {
            treeView.SelectedNode.Remove();
            listView.Items.Clear();
        }
    }
}

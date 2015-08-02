namespace MagicGearEditor3D
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.menuMain = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newMapToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadMapToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveMapToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.heightmapToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importHeightmapMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.exportHeightmapMenu = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mainToolBar = new System.Windows.Forms.ToolStrip();
            this.tbBtnCameraCtrl = new System.Windows.Forms.ToolStripButton();
            this.tbBtnHeightmap = new System.Windows.Forms.ToolStripButton();
            this.tbBtnLayers = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.mainStatus = new System.Windows.Forms.StatusStrip();
            this.statusInfo = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuMain.SuspendLayout();
            this.mainToolBar.SuspendLayout();
            this.mainStatus.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuMain
            // 
            this.menuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.heightmapToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuMain.Location = new System.Drawing.Point(0, 0);
            this.menuMain.Name = "menuMain";
            this.menuMain.Size = new System.Drawing.Size(617, 24);
            this.menuMain.TabIndex = 0;
            this.menuMain.Text = "menuMain";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newMapToolStripMenuItem,
            this.loadMapToolStripMenuItem,
            this.saveMapToolStripMenuItem,
            this.toolStripSeparator2,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(35, 20);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // newMapToolStripMenuItem
            // 
            this.newMapToolStripMenuItem.Name = "newMapToolStripMenuItem";
            this.newMapToolStripMenuItem.Size = new System.Drawing.Size(159, 22);
            this.newMapToolStripMenuItem.Text = "&New Map";
            this.newMapToolStripMenuItem.Click += new System.EventHandler(this.newMapToolStripMenuItem_Click);
            // 
            // loadMapToolStripMenuItem
            // 
            this.loadMapToolStripMenuItem.Name = "loadMapToolStripMenuItem";
            this.loadMapToolStripMenuItem.Size = new System.Drawing.Size(159, 22);
            this.loadMapToolStripMenuItem.Text = "&Load Map";
            // 
            // saveMapToolStripMenuItem
            // 
            this.saveMapToolStripMenuItem.Name = "saveMapToolStripMenuItem";
            this.saveMapToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.saveMapToolStripMenuItem.Size = new System.Drawing.Size(159, 22);
            this.saveMapToolStripMenuItem.Text = "&Save Map";
            // 
            // heightmapToolStripMenuItem
            // 
            this.heightmapToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.importHeightmapMenu,
            this.exportHeightmapMenu});
            this.heightmapToolStripMenuItem.Name = "heightmapToolStripMenuItem";
            this.heightmapToolStripMenuItem.Size = new System.Drawing.Size(70, 20);
            this.heightmapToolStripMenuItem.Text = "Heightmap";
            // 
            // importHeightmapMenu
            // 
            this.importHeightmapMenu.Name = "importHeightmapMenu";
            this.importHeightmapMenu.Size = new System.Drawing.Size(121, 22);
            this.importHeightmapMenu.Text = "Import ...";
            // 
            // exportHeightmapMenu
            // 
            this.exportHeightmapMenu.Name = "exportHeightmapMenu";
            this.exportHeightmapMenu.Size = new System.Drawing.Size(121, 22);
            this.exportHeightmapMenu.Text = "Export ...";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(40, 20);
            this.helpToolStripMenuItem.Text = "&Help";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.aboutToolStripMenuItem.Text = "&About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // mainToolBar
            // 
            this.mainToolBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tbBtnCameraCtrl,
            this.tbBtnHeightmap,
            this.tbBtnLayers,
            this.toolStripSeparator1});
            this.mainToolBar.Location = new System.Drawing.Point(0, 24);
            this.mainToolBar.Name = "mainToolBar";
            this.mainToolBar.Size = new System.Drawing.Size(617, 37);
            this.mainToolBar.TabIndex = 1;
            this.mainToolBar.Text = "Editor Tools";
            // 
            // tbBtnCameraCtrl
            // 
            this.tbBtnCameraCtrl.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tbBtnCameraCtrl.Image = ((System.Drawing.Image)(resources.GetObject("tbBtnCameraCtrl.Image")));
            this.tbBtnCameraCtrl.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tbBtnCameraCtrl.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tbBtnCameraCtrl.Name = "tbBtnCameraCtrl";
            this.tbBtnCameraCtrl.Size = new System.Drawing.Size(34, 34);
            this.tbBtnCameraCtrl.Text = "Camera Control";
            // 
            // tbBtnHeightmap
            // 
            this.tbBtnHeightmap.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tbBtnHeightmap.Image = ((System.Drawing.Image)(resources.GetObject("tbBtnHeightmap.Image")));
            this.tbBtnHeightmap.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tbBtnHeightmap.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tbBtnHeightmap.Name = "tbBtnHeightmap";
            this.tbBtnHeightmap.Size = new System.Drawing.Size(34, 34);
            this.tbBtnHeightmap.Text = "Edit Height map";
            // 
            // tbBtnLayers
            // 
            this.tbBtnLayers.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tbBtnLayers.Image = ((System.Drawing.Image)(resources.GetObject("tbBtnLayers.Image")));
            this.tbBtnLayers.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
            this.tbBtnLayers.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tbBtnLayers.Name = "tbBtnLayers";
            this.tbBtnLayers.Size = new System.Drawing.Size(34, 34);
            this.tbBtnLayers.Text = "Edit texture layers";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 37);
            // 
            // mainStatus
            // 
            this.mainStatus.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.statusInfo});
            this.mainStatus.Location = new System.Drawing.Point(0, 394);
            this.mainStatus.Name = "mainStatus";
            this.mainStatus.Size = new System.Drawing.Size(617, 22);
            this.mainStatus.TabIndex = 2;
            this.mainStatus.Text = "statusStrip1";
            // 
            // statusInfo
            // 
            this.statusInfo.Name = "statusInfo";
            this.statusInfo.Size = new System.Drawing.Size(38, 17);
            this.statusInfo.Text = "Ready";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(156, 6);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(159, 22);
            this.exitToolStripMenuItem.Text = "E&xit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(617, 416);
            this.Controls.Add(this.mainStatus);
            this.Controls.Add(this.mainToolBar);
            this.Controls.Add(this.menuMain);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuMain;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MagicGearEditor3D";
            this.menuMain.ResumeLayout(false);
            this.menuMain.PerformLayout();
            this.mainToolBar.ResumeLayout(false);
            this.mainToolBar.PerformLayout();
            this.mainStatus.ResumeLayout(false);
            this.mainStatus.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuMain;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newMapToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadMapToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveMapToolStripMenuItem;
        private System.Windows.Forms.ToolStrip mainToolBar;
        private System.Windows.Forms.StatusStrip mainStatus;
        private System.Windows.Forms.ToolStripButton tbBtnCameraCtrl;
        private System.Windows.Forms.ToolStripStatusLabel statusInfo;
        private System.Windows.Forms.ToolStripButton tbBtnHeightmap;
        private System.Windows.Forms.ToolStripButton tbBtnLayers;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem heightmapToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem importHeightmapMenu;
        private System.Windows.Forms.ToolStripMenuItem exportHeightmapMenu;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
    }
}


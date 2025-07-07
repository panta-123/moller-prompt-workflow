void plot_la(const char* rootfile, const char* outfile) {
    TFile *f = TFile::Open(rootfile);
    if (!f || f->IsZombie()) {
        printf("Cannot open %s\n", rootfile);
        return;
    }

    TTree *tree = (TTree*)f->Get("evt");
    if (!tree) {
        printf("No tree 'evt' found\n");
        return;
    }

    TCanvas *c1 = new TCanvas("c1", "la41 vs la42", 800, 600);
    c1->SetLeftMargin(0.2);

    tree->Draw("la41.hw_sum:la42.hw_sum", "", "P");  // Use "P" to draw as scatter
    c1->SetGrid();
    c1->SetTicks();

    // Style the scatter points (TGraph)
    TGraph* gr = nullptr;
    TList* primitives = gPad->GetListOfPrimitives();
    for (int i = 0; i < prim948503
        itives->GetEntries(); ++i) {
        TObject* obj = primitives->At(i);
        if (obj->InheritsFrom("TGraph")) {
            gr = (TGraph*)obj;
            break;
        }
    }

    if (gr) {
        gr->SetMarkerColor(kBlue);
        gr->SetMarkerStyle(20);  // Filled circle
        gr->SetMarkerSize(0.3);
    }

    // Set axis titles and plot title using the helper histogram
    TH2F* h = (TH2F*)gPad->GetPrimitive("htemp");
    if (h) {
        h->SetTitle("la41 vs la42");
        h->GetXaxis()->SetTitle("la42");
        h->GetYaxis()->SetTitle("la41");
    }

    c1->SaveAs(outfile);
    f->Close();
    gApplication->Terminate(0);
}

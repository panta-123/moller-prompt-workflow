void plot_bpm_and_exit(const char* rootfile, const char* outfile) {
    TFile *f = TFile::Open(rootfile);
    if (!f || f->IsZombie()) { printf("Cannot open %s\n", rootfile); return; }

    TTree *tree = (TTree*)f->Get("evt");
    if (!tree) { printf("No tree 'evt' found\n"); return; }

    TCanvas *c1 = new TCanvas("c1", "bpm1i06XP vs bpm1i06YP", 800, 600);
    c1->SetLeftMargin(0.2);

    tree->Draw("bpm1i06XP.hw_sum:bpm1i06YP.hw_sum", "", "P");
    c1->SetGrid();
    c1->SetTicks();

    // The scatter points are drawn as a TGraph, get it from the pad
    TGraph* gr = nullptr;
    TList* primitives = gPad->GetListOfPrimitives();
    for (int i = 0; i < primitives->GetEntries(); ++i) {
        TObject* obj = primitives->At(i);
        if (obj->InheritsFrom("TGraph")) {
            gr = (TGraph*)obj;
            break;
        }
    }

    if (gr) {
        gr->SetMarkerColor(kBlue);
        gr->SetMarkerStyle(20); // filled circle
        gr->SetMarkerSize(0.3);
    }

    // Now set axis titles via the histogram on the pad
    TH2F* h = (TH2F*)gPad->GetPrimitive("htemp");
    if (h) {
        h->SetTitle("bpm1i06XP vs bpm1i06YP");
        h->GetXaxis()->SetTitle("bpm1i06YP");
        h->GetYaxis()->SetTitle("bpm1i06XP");
    }

    c1->SaveAs(outfile);
    f->Close();
    gApplication->Terminate(0);
}

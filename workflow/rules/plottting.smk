

rule plot_bpm:
    input:
        rootfile = rules.process_raw_to_root.output.rootfile
    output:
        pdf = "plots/bpm1i06XP_vs_bpm1i06YP_run{run}.pdf"
    container:
        image
    log:
        "logs/plot_bpm_{run}.log"
    shell:
        """
        umask 0022
        mkdir -p $(dirname {output.pdf})
        root -l -b -q 'scripts/plot_bpm_and_exit.C("{input.rootfile}","{output.pdf}")' \
             &> {log}
        """

rule plot_la:
    input:
        rootfile = rules.process_raw_to_root.output.rootfile
    output:
        pdf = "plots/la41_vs_la42_run{run}.pdf"
    container:
        image
    log:
        "logs/plot_la_{run}.log"
    shell:
        """
        umask 0022
        mkdir -p $(dirname {output.pdf})
        root -l -b -q 'scripts/plot_la.C("{input.rootfile}","{output.pdf}")' \
             &> {log}
        """
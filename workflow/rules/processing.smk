
rule process_raw_to_root:
    input:
        qw_data
    output:
        rootfile = f"{qw_rootfiles}/isu_sample_{{run}}.root"
    container:
        image
    params:
        outdir = lambda wildcards, output: os.path.dirname(output.rootfile)
    log:
        "logs/process_raw_to_root_{run}.log"
    shell:
        """
        export QW_DATA={input}
        export QW_ROOTFILES={params.outdir}
        umask 0022
        qwparity -r {wildcards.run} --config qwparity_simple.conf \
                --detectors mock_newdets.map --datahandlers mock_datahandlers.map \
                --QwLog.loglevel-file 2 \
                --QwLog.logfile {log} &>> {log}    
        """